#include "GameServer.h"
#include "Socket_System.h"
bool GameServer::Initialize()
{
	Socket_System::GetInstance().Initialize();
	return true;
}

void GameServer::Tick()
{
}

void GameServer::Destroy()
{
}
