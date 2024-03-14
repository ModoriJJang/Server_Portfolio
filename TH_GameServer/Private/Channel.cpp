#include "Channel.h"
#include <iostream>
bool Channel::Initialize()
{ 
	printf( "[Channel] CreateChannel %d\n", _channel_ID );
	_world = new World();

	return false;
}

void Channel::Tick( float DeltaTime )
{
}

void Channel::Destroy()
{
	delete _world;
	_world = nullptr;
}
