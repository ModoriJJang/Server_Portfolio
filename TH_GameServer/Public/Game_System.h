#pragma once

#include "Server.h"
#include <unordered_map>
#include <vector>
#include <thread>

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
	void Tick( float DeltaTime );
	void Server_Tick( float DeltaTime );
	void Destroy();
	
public:
	void Create_Worlds();
	void Create_Worlds_Thread();

	void Replication_Player(int server, int channel, Player player);

	Player& Get_Player(int server, int channel, std::string playerID);

	void Add_Player( int server, int channel, std::string playerID );

	int Add_Player_In_Server();
	void Remove_Player_In_Server( int PlayerId );

	unsigned int Get_Network_ID()
	{
		return _network_ID++;
	}

public:
	std::unordered_map<SERVER_NAME, Server*>_servers;
	
	unsigned int _network_ID;
};

