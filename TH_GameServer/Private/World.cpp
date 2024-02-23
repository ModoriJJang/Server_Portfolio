#include "World.h"

bool World::Initialize()
{
    return false;
}

void World::Tick()
{
    for ( auto& player : _players )
    {
        player.second->Tick();
    }
}

void World::Destroy()
{
}

void World::Add_Player( int playerId, Player* player )
{
    _players.insert( std::make_pair( playerId, player ) );
    printf("Player 생성 PlayerId : %d\n",playerId);
}

int World::Get_New_PlayerId()
{
    return _playerIdCount++;
}

void World::Remove_Player( int playerId )
{
    delete _players[playerId];
    _players[playerId] = nullptr;
    _players.erase( playerId );

    printf("Player 삭제 PlayerId : %d\n",playerId);
}
