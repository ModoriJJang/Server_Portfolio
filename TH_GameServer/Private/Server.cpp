#include "Server.h"
#include <thread>
bool Server::Initialize()
{
    _channels = new Channel[MAX_CHANNEL];

    for ( size_t index = 0; index < MAX_CHANNEL; index++ )
    {
        _channels[index].Initialize();
        printf( "[World] Channel %d Init \n", (int)index );
    }
    return true;
}

void Server::Tick()
{
    for ( size_t index = 0; index < MAX_CHANNEL; index++ )
    {
        _channels[index].Tick();
    }
}

void Server::Destroy()
{
    delete[] _channels;
    _channels = nullptr;
}

void Server::Add_Player( int playerId, Player* player )
{
    _players.insert( std::make_pair( playerId, player ) );
    printf("Player ���� PlayerId : %d\n",playerId);
}

int Server::Get_New_PlayerId()
{
    return _playerIdCount++;
}

void Server::Remove_Player( int playerId )
{
    delete _players[playerId];
    _players[playerId] = nullptr;
    _players.erase( playerId );

    printf("Player ���� PlayerId : %d\n",playerId);
}
