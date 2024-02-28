#pragma once

#include "../FlatBuffers/GamePacket_generated.h"

#include <sstream>

#include "Socket_System.h"

using namespace TH_Server::TH_Packet;

class Packet_System
{
public:
	static Packet_System& GetInstance()
	{
		static Packet_System instance;
		return instance;
	}


public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	void ReceivePacket(PSocketContext client, char* recvPacket);
	void SendPacket(PSocketContext client, std::vector<flatbuffers::Offset<Packet>>& packets);
	void BroadcastPacket( std::stringstream& sendPacket);

private:
	static void Login_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet );
	static void Chat_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet );
	static void Player_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet );
};

