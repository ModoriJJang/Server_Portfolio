#pragma once

#include <unordered_map>
#include <string>
#include <Player.h>

#include "World.h"
class Channel
{
public:
	bool Initialize();
	void Tick( float DeltaTime );
	void Destroy();

public:
	void Set_Channel_ID( int channel_ID )
	{
		_channel_ID = channel_ID;
	}

private:
	int _channel_ID;
	World* _world;
 
public:
	std::unordered_map<std::string, Player*> _players;
	
};

