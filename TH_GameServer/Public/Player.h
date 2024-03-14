#pragma once
#include "Socket_System.h"
#include "GameObject.h"

#include <string>

class Player :  GameObject
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	std::string _ClientID;
	float _x;
	float _y;
	float _z;
	PSocketContext _client;
};

