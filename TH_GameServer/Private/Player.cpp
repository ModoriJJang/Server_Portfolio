#include "Player.h"
#include <stdio.h>



bool Player::Initialize()
{
	return false;
}

void Player::Tick()
{
}

void Player::Destroy()
{
}

void Player::Set_Position( const TH_Server::TH_Packet::Vector3* position )
{
	//_x = position->x();
	//_y = position->y();
	//_z = position->z();

	_position = *position;
	_Updated = true;
	printf( "Player Update True" );
}

TH_Server::TH_Packet::Vector3* Player::Get_Position()
{
	return &_position;
}
