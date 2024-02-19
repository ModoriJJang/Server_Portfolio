#include "Socket_System.h"
#include <thread>
#include <iostream>

unsigned int WINAPI StartWorkerThread(void* src)
{
	Socket_System* socketSystem = (Socket_System*)src;
	socketSystem->Recv();

	return 0;
}

bool Socket_System::Initialize()
{
	CheckSystemInfo();
	CreateSocket();
	CreateWorkerThread();

	return true;
}

void Socket_System::Tick()
{
}

void Socket_System::Destroy()
{
}

void Socket_System::CheckSystemInfo()
{
	SYSTEM_INFO systemInfo;
	GetSystemInfo(&systemInfo);
	_workerThreadCount = systemInfo.dwNumberOfProcessors * 2; // ���� ���μ��� (������) ī��Ʈ
	printf("[System] Thread Count : %d\n", _workerThreadCount);
}

void Socket_System::CreateSocket()
{
	printf("[System] Start CreateSocket\n");
	// Winsock ����
	WSADATA wsaData;
	if ( WSAStartup( MAKEWORD( 2, 2 ), &wsaData ) != NULL )
	{
		return;
	}
	
	// Completion Port ����
	_completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, NULL);
	if (_completionPort == NULL)
	{
		WSACleanup();
		return;
	}
	
	// Listen Socket ����
	_listenSocket = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_listenSocket == INVALID_SOCKET)
	{
		WSACleanup();
		return;
	}

	// Listen Socket�� CompletionPort ����
	CreateIoCompletionPort((HANDLE)_listenSocket, _completionPort, NULL, NULL);

	SOCKADDR_IN serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(1234);

	// Listen Socket IP �ּҿ�����
	if (bind(_listenSocket, (LPSOCKADDR)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

	// Listen Socket ���Ŵ��
	if (listen(_listenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

    GUID GuidAcceptEx = WSAID_ACCEPTEX;
	DWORD dwBytes;

	// AcceptEx �Լ� ����
    if ( WSAIoctl(_listenSocket, SIO_GET_EXTENSION_FUNCTION_POINTER,
		&GuidAcceptEx, sizeof (GuidAcceptEx), 
        &_fnAcceptEx, sizeof (_fnAcceptEx), 
        &dwBytes, NULL, NULL) 
		== SOCKET_ERROR )
	{
        closesocket(_listenSocket);
		WSACleanup();
        return;
    }

	// Accept Socket ����
	_acceptSocket = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_acceptSocket == INVALID_SOCKET)
	{
		closesocket(_acceptSocket);
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

	WSAOVERLAPPED overlapped;
	ZeroMemory(&overlapped, sizeof(overlapped));
	char outputBuffer[4096];

	// �񵿱� Accept ��� ����
	if (_fnAcceptEx( _listenSocket, _acceptSocket, &outputBuffer,
		NULL,
		sizeof( SOCKADDR_IN ) + 16, sizeof( SOCKADDR_IN ) + 16,
		NULL, &overlapped ) 
		&& WSAGetLastError() != WSA_IO_PENDING) // WSA_IO_PENDING ��ġ�� �۾� ���� �Ϸ� ���� (�����ƴ�)
	{
		printf("[System Info] Ŭ���̾�Ʈ ���� ����");
		closesocket(_acceptSocket);
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

	printf("[System] Success CreateSocket\n");
}

void Socket_System::CreateWorkerThread()
{
	printf("[System] Start Create WorkerThread\n");

	unsigned int threadID;

	_workerThreadHandle = new HANDLE[_workerThreadCount];

	for (int index = 0; index < _workerThreadCount; ++index)
	{
		_workerThreadHandle[index] = (HANDLE*)_beginthreadex(NULL, 0, StartWorkerThread, (void*)this, CREATE_SUSPENDED, &threadID);
		if (_workerThreadHandle[index] == NULL)
		{
			printf("[Error] Failed Crate WorkerThread\n");
			return;
		}
		ResumeThread(_workerThreadHandle[index]);
	}
	printf("[System] Success Create WorkerThread\n");
}

void Socket_System::Recv()
{
	while (true)
	{
		PSocketContext clientKey = NULL;

		WSAOVERLAPPED overlapped;
		ZeroMemory(&overlapped, sizeof(overlapped));

		DWORD byte = 0;
		DWORD flags = 0;
		

		BOOL result = GetQueuedCompletionStatus(_completionPort, &byte, (PULONG_PTR)&clientKey, (LPOVERLAPPED*)&overlapped, INFINITE);

		if (clientKey == nullptr)
		{
			clientKey = new SocketContext();
			clientKey->socket = _acceptSocket;
			clientKey->wsaOverlapped = overlapped;
			clientKey->dataBuffer.len = 4096;
			clientKey->dataBuffer.buf = clientKey->messageBuffer;
			CreateIoCompletionPort((HANDLE)_acceptSocket, _completionPort, (ULONG_PTR)clientKey, NULL);
			_connectClients.insert(clientKey);
		}

		if (result == FALSE && byte == 0)
		{
			printf("[System Info] Ŭ���̾�Ʈ ���� ���� : %d\n", clientKey->socket);
			closesocket(clientKey->socket);
			_connectClients.erase(clientKey);
			continue;
		}

		switch (clientKey->IoState)
		{
			case IO_Accept:
			{
				clientKey->IoState = IO_Recv;

				printf("[Thread] : %i / [Socket] : %i\n", std::this_thread::get_id(), clientKey->socket);

				WSARecv(clientKey->socket, &clientKey->dataBuffer, 1, NULL, &flags, &clientKey->wsaOverlapped, NULL);

				_acceptSocket = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
				if (_acceptSocket == INVALID_SOCKET)
				{
					closesocket(_acceptSocket);
					closesocket(_listenSocket);
					WSACleanup();
					return;
				}

				ZeroMemory(&overlapped, sizeof(overlapped));
				char outputBuffer[4096];

				// �񵿱� Accept ��� ����
				if (_fnAcceptEx( _listenSocket, _acceptSocket, &outputBuffer,
					NULL,
					sizeof( SOCKADDR_IN ) + 16, sizeof( SOCKADDR_IN ) + 16,
					NULL, &overlapped ) 
					&& WSAGetLastError() != WSA_IO_PENDING) // WSA_IO_PENDING ��ġ�� �۾� ���� �Ϸ� ���� (�����ƴ�)
				{
					printf("[System Info] Ŭ���̾�Ʈ ���� ����");
					closesocket(_acceptSocket);
					closesocket(_listenSocket);
					WSACleanup();
					return;
				}

				break;
			}
			case IO_Recv:
			{
				int result = WSARecv(clientKey->socket, &clientKey->dataBuffer, 1, NULL, &flags, &clientKey->wsaOverlapped, NULL);
				printf("[Thread] : %i / %i\n", std::this_thread::get_id(), clientKey->socket);


				//stringstream recvPacket;
				//int packetType;
				//recvPacket << clientKey->messageBuffer;
				//recvPacket >> packetType;

				//cout << clientKey->messageBuffer << endl;


				break;
			}
		}
	}
}

void Socket_System::Send( PSocketContext socketContext, stringstream& message )
{
	DWORD sendBytes;
	DWORD flags = 0;

	memcpy(socketContext->messageBuffer, (CHAR*)message.str().c_str(), message.str().length());
	socketContext->dataBuffer.buf = socketContext->messageBuffer;
	socketContext->dataBuffer.len = message.str().length();
	WSASend(socketContext->socket, &socketContext->dataBuffer, 1, &sendBytes, flags, NULL, NULL);
}

void Socket_System::Broadcast( stringstream& message )
{
	for ( auto& client : _connectClients )
	{
		Send(client, message);
	}
}