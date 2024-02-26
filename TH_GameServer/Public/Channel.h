#pragma once

#include "World.h"
class Channel
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	void Set_Channel_ID( int channel_ID )
	{
		_channel_ID = channel_ID;
	}

private:
	int _channel_ID;
	World* _world;
};

