#pragma once

#include <sstream>

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
	void PacketProcess( std::stringstream& recvPacket );
	void ReceivePacket(char* recvPacket);
	void BroadcastPacket( std::stringstream& sendPacket);
};

