#pragma once

class GameServer
{
public:
	GameServer() = default;
	~GameServer() = default;

public:
	bool Initialize();
	void Tick();
	void Destroy();
};

