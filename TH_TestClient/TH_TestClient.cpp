// TH_TestClient.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "../TH_GameServer/FlatBuffers/GamePacket_generated.h"

#include <iostream>
#include <string>
#include <sstream>
#include <thread>

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <ws2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

using namespace std;

#define SERVER_PORT 1234
#define SERVER_IP "127.0.0.1"


using namespace TH_Server::TH_Packet;

static void ReceiveMessage(SOCKET serverSocket)
{
	char recvData[4096] = { 0, };
	while (true)
	{
		recv(serverSocket, recvData, 4096, NULL);

	}

	return;
}

int main()
{
    WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != ERROR_SUCCESS)
		return -1;

	SOCKET serverSocket;
	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET)
	{
		WSACleanup();
		return -1;
	}

	SOCKADDR_IN serverAddress;
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
	serverAddress.sin_port = htons(SERVER_PORT);

	int connectResult = connect(serverSocket, (LPSOCKADDR)&serverAddress, sizeof(serverAddress));

	if (connectResult != ERROR_SUCCESS)
	{
		cout << "서버연결실패" << endl;
		closesocket(serverSocket);
		WSACleanup();
		return -1;
	}
	cout << "서버연결성공" << endl;

	flatbuffers::FlatBufferBuilder builder( 4096 );
	auto packet1 = CreatePacket( builder, PacketData_LOGIN, CreateLOGIN_DATA(builder, builder.CreateString("token1")).Union());

	builder.Finish( packet1 );

	std::vector<flatbuffers::Offset<Packet>> packets;
	packets.emplace_back(packet1);


	auto protocol = CreateProtocol( builder, builder.CreateString("test"), EServer_Server_1, 1, builder.CreateVector(packets));
	builder.Finish( protocol );

	auto sendPacket = builder.GetBufferPointer();

	auto temp = GetProtocol( (char*) sendPacket );
	auto temp2 = temp->clientid()->str();

	DWORD flags = 0;

	send( serverSocket, (char*)sendPacket, 4096, 0 );

	char recvData[4096] = { 0, };
	recv(serverSocket, recvData, 4096, NULL);
	int a = 0;
	while (true)
	{
	}

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
