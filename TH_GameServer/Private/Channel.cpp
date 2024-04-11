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
			printf("[Player] [%s] [ X : %f / Y : %f / Z : %f\n",player.first.c_str(), player.second->_position.x(), player.second->_position.y(), player.second->_position.z());
			Packet_System::GetInstance().Make_Player_Packet( *player.second );

			player.second->_Updated = false;
		}
	}
}

void Channel::Destroy()
{
	delete _world;
	_world = nullptr;
}
