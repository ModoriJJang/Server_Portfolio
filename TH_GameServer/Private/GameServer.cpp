#include "Packet_System.h"
#include "GameServer.h"
#include "Socket_System.h"
#include "Game_System.h"
#include "gRPC_System.h"

#include "Database_System.h"

bool GameServer::Initialize()
{
	Game_System::GetInstance().Initialize();
	Socket_System::GetInstance().Initialize();
	Packet_System::GetInstance().Initialize();
	gRPC_System::GetInstance().Initialize();
	Database_System::GetInstance().Initialize();
	return true;
}

void GameServer::Tick( float DeltaTime )
{
	Game_System::GetInstance().Tick( DeltaTime );
	Packet_System::GetInstance().Tick( DeltaTime );
	gRPC_System::GetInstance().Tick();
}

void GameServer::Destroy()
{
	Game_System::GetInstance().Destroy();
	Packet_System::GetInstance().Destroy();
	Socket_System::GetInstance().Destroy();
	gRPC_System::GetInstance().Destroy();
	Database_System::GetInstance().Destroy();
}
