#include "GameServer.h"
#include "Socket_System.h"
#include "Game_System.h"
bool GameServer::Initialize()
{
	Game_System::GetInstance().Initialize();
	Socket_System::GetInstance().Initialize();
	return true;
}

void GameServer::Tick()
{
	Game_System::GetInstance().Tick();
}

void GameServer::Destroy()
{
	Game_System::GetInstance().Destroy();
	Socket_System::GetInstance().Destroy();
}
