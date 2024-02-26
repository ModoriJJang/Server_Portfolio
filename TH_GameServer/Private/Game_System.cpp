#include "Game_System.h"



void World_Tick( Server* world )
{
	world->Tick();
}

bool Game_System::Initialize()
{
	Create_Worlds();
	return true;
}

void Game_System::Tick()
{
	//Create_Worlds_Thread();
	//_world->Tick();
}

void Game_System::Destroy()
{
	for(auto& world : _worlds )
	{
		delete world.second;
		world.second = nullptr;
	}

	_worlds.clear();
}

void Game_System::Create_Worlds()
{
	for ( int worldName = 0; worldName < (int)SERVER_NAME::SERVER_END; worldName++ )
	{
		Server* world = new Server();
		world->Initialize();
		_worlds.insert( std::make_pair( (SERVER_NAME)worldName, world) );
		printf( "[Game_System} Create World %d\n", worldName );
	}
}

void Game_System::Create_Worlds_Thread()
{
	std::vector<std::thread> _worldThreads;
	_worldThreads.reserve( _worlds.size() );
	for ( auto& world : _worlds )
	{
		_worldThreads.emplace_back( std::thread( World_Tick, world.second ) );
	}

	for (auto& thread : _worldThreads)
            thread.join();
}

int Game_System::Add_Player_In_Server()
{
	/*Player* player = new Player();
	int playerId = _world->Get_New_PlayerId();
	player->_ID = playerId;
	_world->Add_Player( playerId , player);

	return playerId;*/
	return 0;
}



void Game_System::Remove_Player_In_Server( int PlayerId )
{
	//_world->Remove_Player( PlayerId );
}


