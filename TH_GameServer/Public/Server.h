#pragma once

#include <unordered_map>
#include "Player.h"
#include "Channel.h"

enum SERVER_NAME
{
	SERVER_0,
	SERVER_1,
	SERVER_END,
};

class Server
{
public:
	bool Initialize();
	void Tick( float DeltaTime );
	void Destroy();

public:
	void Add_Player( int playerId, Player* player );
	int Get_New_PlayerId();
	void Remove_Player( int playerId );

	std::unordered_map<int, Player*> _players;

	int _playerIdCount = 0;

	Channel* _channels;
	const int MAX_CHANNEL = 10;
};

