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
	void ReceivePacket(char* recvPacket);
	void SendPacket(char* sendPacket);
	void BroadcastPacket( std::stringstream& sendPacket);
};

