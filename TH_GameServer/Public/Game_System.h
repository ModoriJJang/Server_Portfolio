#pragma once

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
	int Add_Player_In_Server();
	void Remove_Player_In_Server( int PlayerId );

public:
	class World* _world;
};

