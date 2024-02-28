#include "Packet_System.h"
#include "Socket_System.h"
#include <thread>
#include <iostream>

#include "Game_System.h"

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

	Packet_System::GetInstance().Initialize();

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
	_workerThreadCount = systemInfo.dwNumberOfProcessors * 2; // 논리 프로세서 (스레드) 카운트
	printf("[System] Thread Count : %d\n", _workerThreadCount);
}

void Socket_System::CreateSocket()
{
	printf("[System] Start CreateSocket\n");
	// Winsock 시작
	WSADATA wsaData;
	if ( WSAStartup( MAKEWORD( 2, 2 ), &wsaData ) != NULL )
	{
		return;
	}
	
	// Completion Port 생성
	_completionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, NULL, NULL);
	if (_completionPort == NULL)
	{
		WSACleanup();
		return;
	}
	
	// Listen Socket 생성
	_listenSocket = WSASocketW(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0, WSA_FLAG_OVERLAPPED);
	if (_listenSocket == INVALID_SOCKET)
	{
		WSACleanup();
		return;
	}

	// Listen Socket을 CompletionPort 연결
	CreateIoCompletionPort((HANDLE)_listenSocket, _completionPort, NULL, NULL);

	SOCKADDR_IN serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
	serverAddress.sin_port = htons(1234);

	// Listen Socket IP 주소에연결
	if (bind(_listenSocket, (LPSOCKADDR)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

	// Listen Socket 수신대기
	if (listen(_listenSocket, SOMAXCONN) == SOCKET_ERROR)
	{
		closesocket(_listenSocket);
		WSACleanup();
		return;
	}

    GUID GuidAcceptEx = WSAID_ACCEPTEX;
	DWORD dwBytes;

	// AcceptEx 함수 생성
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

	// Accept Socket 생성
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

	// 비동기 Accept 대기 시작
	if (_fnAcceptEx( _listenSocket, _acceptSocket, &outputBuffer,
		NULL,
		sizeof( SOCKADDR_IN ) + 16, sizeof( SOCKADDR_IN ) + 16,
		NULL, &overlapped ) 
		&& WSAGetLastError() != WSA_IO_PENDING) // WSA_IO_PENDING 겹치는 작업 추후 완료 예정 (에러아님)
	{
		printf("[System Info] 클라이언트 연결 실패");
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
			
		}

		if (result == FALSE && byte == 0)
		{
			printf("[System Info] 클라이언트 연결 종료 : %d\n", clientKey->socket);

			if ( clientKey->IoState > IO_Login )
			{
				_connectClients.erase(clientKey);
			}
			

			closesocket(clientKey->socket);
			
			Game_System::GetInstance().Remove_Player_In_Server( clientKey->ClientId );
			continue;
		}

		switch (clientKey->IoState)
		{
			case IO_Accept:
			{
				clientKey->IoState = IO_Login;

				printf("[Thread] : %i / [Socket] : %i\n", std::this_thread::get_id(), clientKey->socket);

				WSARecv(clientKey->socket, &clientKey->dataBuffer, 1, NULL, &flags, &clientKey->wsaOverlapped, NULL);
				clientKey->ClientId = Game_System::GetInstance().Add_Player_In_Server();
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

				// 비동기 Accept 대기 시작
				if (_fnAcceptEx( _listenSocket, _acceptSocket, &outputBuffer,
					NULL,
					sizeof( SOCKADDR_IN ) + 16, sizeof( SOCKADDR_IN ) + 16,
					NULL, &overlapped ) 
					&& WSAGetLastError() != WSA_IO_PENDING) // WSA_IO_PENDING 겹치는 작업 추후 완료 예정 (에러아님)
				{
					printf("[System Info] 클라이언트 연결 실패");
					closesocket(_acceptSocket);
					closesocket(_listenSocket);
					WSACleanup();
					return;
				}

				break;
			}
			case IO_Login:
			{
				WSARecv(clientKey->socket, &clientKey->dataBuffer, 1, NULL, &flags, &clientKey->wsaOverlapped, NULL);
				printf("[Thread] : %i / %i\n", std::this_thread::get_id(), clientKey->socket);

				Packet_System::GetInstance().ReceivePacket( clientKey, clientKey->messageBuffer);

				_connectClients.insert(clientKey);
				clientKey->IoState = IO_Recv;
				break;
			}
			case IO_Recv:
			{
				WSARecv(clientKey->socket, &clientKey->dataBuffer, 1, NULL, &flags, &clientKey->wsaOverlapped, NULL);
				printf("[Thread] : %i / %i\n", std::this_thread::get_id(), clientKey->socket);

				Packet_System::GetInstance().ReceivePacket( clientKey, clientKey->messageBuffer);

				break;
			}
		}
	}
}

void Socket_System::Send( PSocketContext socketContext, unsigned char* sendPacket )
{
	DWORD sendBytes;
	DWORD flags = 0;
	ULONG lenght = 4096;

	memcpy(socketContext->messageBuffer, sendPacket, lenght);
	socketContext->dataBuffer.buf = socketContext->messageBuffer;
	socketContext->dataBuffer.len = lenght;
	WSASend(socketContext->socket, &socketContext->dataBuffer, 1, &sendBytes, flags, NULL, NULL);
}

void Socket_System::Broadcast( unsigned char* sendPacket )
{
	for ( auto& client : _connectClients )
	{
		Send(client, sendPacket);
	}
}
