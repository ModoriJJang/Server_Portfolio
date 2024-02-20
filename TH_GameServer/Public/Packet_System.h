#pragma once

#include <sstream>

using namespace std;

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
	void PacketProcess( stringstream& recvPacket );
};

