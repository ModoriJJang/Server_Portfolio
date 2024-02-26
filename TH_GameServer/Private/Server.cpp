#include "Server.h"
#include <thread>
bool Server::Initialize()
{
    _channels = new Channel[MAX_CHANNEL];

    for ( size_t index = 0; index < MAX_CHANNEL; index++ )
    {
        _channels[index].Set_Channel_ID( index );
        _channels[index].Initialize();
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
    printf("Player 생성 PlayerId : %d\n",playerId);
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

    printf("Player 삭제 PlayerId : %d\n",playerId);
}
