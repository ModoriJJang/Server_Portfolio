#pragma once

#include <unordered_map>
#include "Player.h"
class World
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	void Add_Player( int playerId, Player* player );
	int Get_New_PlayerId();
	void Remove_Player( int playerId );

	std::unordered_map<int, Player*> _players;

	int _playerIdCount = 0;
};

