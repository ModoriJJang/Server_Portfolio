#pragma once
#include "../FlatBuffers/GamePacket_generated.h"
#include "Socket_System.h"
#include "GameObject.h"

#include <string>

class Player : public GameObject
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	TH_Server::TH_Packet::Vector3 _position;
	std::string _ClientID;
	float _x;
	float _y;
	float _z;
	PSocketContext _client;
};

