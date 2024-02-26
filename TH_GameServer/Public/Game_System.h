#pragma once

#include "Server.h"
#include <unordered_map>
#include <vector>
#include <thread>
enum WORLD_NAME
{
	WORLD_0,
	WORLD_1,
	WORLD_END,
};

class Game_System
{
public:
	static Game_System& GetInstance()
	{
		static Game_System instance;
		return instance;
	}

public:
	bool Initialize();
	void Tick();
	void Destroy();
	
public:
	void Create_Worlds();
	void Create_Worlds_Thread();

	int Add_Player_In_Server();
	void Remove_Player_In_Server( int PlayerId );

public:
	std::unordered_map<WORLD_NAME, Server*>_worlds;
	
	unsigned int _NetworkID;
};

