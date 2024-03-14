#pragma once

class GameServer
{
public:
	GameServer() = default;
	~GameServer() = default;

public:
	bool Initialize();
	void Tick( float DeltaTime );
	void Destroy();
};

