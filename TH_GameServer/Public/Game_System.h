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
};

