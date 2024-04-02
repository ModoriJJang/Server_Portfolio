#include <Packet_System.h>
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

void Channel::Server_Tick( float DeltaTime )
{
	for ( auto& player : _players )
	{
		if ( player.second->_Updated == true )
		{
			Packet_System::GetInstance().Make_Player_Packet( *player.second );
		}
	}
}

void Channel::Destroy()
{
	delete _world;
	_world = nullptr;
}
