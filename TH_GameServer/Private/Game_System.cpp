#include "Game_System.h"

#include "World.h"

bool Game_System::Initialize()
{
    _world = new World();
    return false;
}

void Game_System::Tick()
{
    _world->Tick();
}

void Game_System::Destroy()
{
}

int Game_System::Add_Player_In_Server()
{
    Player* player = new Player();
    int playerId = _world->Get_New_PlayerId();
    player->_ID = playerId;
    _world->Add_Player( playerId , player);

    return playerId;
}

void Game_System::Remove_Player_In_Server( int PlayerId )
{
    _world->Remove_Player( PlayerId );
}
