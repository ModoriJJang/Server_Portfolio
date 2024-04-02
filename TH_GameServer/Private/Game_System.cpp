#include "Game_System.h"



void World_Tick( Server* world )
{
	//world->Tick();
}

bool Game_System::Initialize()
{
	Create_Worlds();
	return true;
}

void Game_System::Tick( float DeltaTime )
{
	//Create_Worlds_Thread();
	//_world->Tick();
	for(auto& server : _servers )
	{
		server.second->Tick( DeltaTime );
	}
}

void Game_System::Server_Tick( float DeltaTime )
{
	for(auto& server : _servers )
	{
		server.second->Server_Tick( DeltaTime );
	}
}

void Game_System::Destroy()
{
	for(auto& server : _servers )
	{
		delete server.second;
		server.second = nullptr;
	}

	_servers.clear();
}

void Game_System::Create_Worlds()
{
	for ( int serverName = 0; serverName < (int)SERVER_NAME::SERVER_END; serverName++ )
	{
		Server* server = new Server();
		server->Initialize();
		_servers.insert( std::make_pair( (SERVER_NAME)serverName, server) );
		printf( "[Game_System} Create World %d\n", serverName );
	}
}

void Game_System::Create_Worlds_Thread()
{
	std::vector<std::thread> _worldThreads;
	_worldThreads.reserve( _servers.size() );
	for ( auto& world : _servers )
	{
		_worldThreads.emplace_back( std::thread( World_Tick, world.second ) );
	}

	for (auto& thread : _worldThreads)
            thread.join();
}

void Game_System::Replication_Player( int server, int channel, Player player )
{
}

Player& Game_System::Get_Player(int server, int channel, std::string playerID)
{
	return *_servers[(SERVER_NAME) server]->_channels[channel]._players[playerID];	 
}

void Game_System::Add_Player(int server, int channel, std::string playerID)
{
	_servers[(SERVER_NAME) server]->_channels[channel]._players.insert( make_pair(playerID, new Player()));
	 
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


