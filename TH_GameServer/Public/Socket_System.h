#pragma once

#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#include <MSWSock.h>
#pragma comment (lib, "mswsock.lib")

#include<set>
#include<list>
#include <sstream>

typedef enum _IO_State
{
	IO_None,
	IO_Accept,
	IO_Login,
	IO_Recv,
	IO_Send,
}IO_State, * PIO_State;

typedef struct _SocketContext
{
	SOCKET socket;
	int ClientId;
	WSAOVERLAPPED wsaOverlapped;
	WSABUF dataBuffer;
	char messageBuffer[4096];
	IO_State IoState;
}SocketContext, * PSocketContext;

class Socket_System
{
public:
	static Socket_System& GetInstance()
	{
		static Socket_System instance;
		return instance;
	}

public:
	bool Initialize();
	void Tick( float DeltaTime );
	void Destroy();

private:
	void CheckSystemInfo();
	void CreateSocket();
	void CreateWorkerThread();

public:
	void Recv();
	void Send(PSocketContext socketContext, unsigned char* sendPacket, int len);
	void Broadcast( unsigned char* sendPacket, int len);
	void Broadcast( unsigned char* sendPacket, int len, std::list<PSocketContext> targetClients);

private:
	int _workerThreadCount = 0;

	HANDLE* _workerThreadHandle;
	HANDLE _completionPort;
	SOCKET _listenSocket;
	SOCKET _acceptSocket;

	LPFN_ACCEPTEX _fnAcceptEx = NULL;
	std::set<PSocketContext> _connectClients;


};

