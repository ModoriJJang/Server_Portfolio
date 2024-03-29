#include "Packet_System.h"

#include"Chat_System.h"
#include "Socket_System.h"
#include "Database_System.h"
#include "Game_System.h"

#include <vector>

void(*func_PacketProcess[PacketData_MAX] )( PSocketContext client, const Protocol* protocol, const void* packet );

bool Packet_System::Initialize()
{
	func_PacketProcess[PacketData_LOGIN] = Login_PacketProcess;
	func_PacketProcess[PacketData_CHAT] = Chat_PacketProcess;
	func_PacketProcess[PacketData_PLAYER] = Player_PacketProcess;
	
	return false;
}

void Packet_System::Tick( float DeltaTime )
{
	broadcastTime += DeltaTime;
	if ( broadcastTime > 12.f / 60.f )
	{
		broadcastTime = 0.f;

		if ( _serverPackets.empty() == false )
		{
			auto clientProtocol = CreateProtocol( _serverBuilder, _serverBuilder.CreateString("Server"), EServer_MIN, 0, _serverBuilder.CreateVector(_serverPackets));
			_serverBuilder.Finish( clientProtocol );

			Socket_System::GetInstance().Broadcast( _serverBuilder.GetBufferPointer(), _serverBuilder.GetSize() );

			_serverBuilder.Clear();

			_serverPackets.clear();
		}
	}
}

void Packet_System::Destroy()
{
}

void Packet_System::ReceivePacket(PSocketContext client, char* recvPacket)
{
	auto protocol = GetProtocol( recvPacket );

	if ( protocol == nullptr )
	{
		return;
	}

	std::string clientID = protocol->clientid()->str();

	auto packets = protocol->packet();

	if ( packets == nullptr )
	{
		return;
	}

	for ( auto iter = packets->begin(); iter != packets->end(); iter++ )
	{
		(*func_PacketProcess[iter->data_type()]) ( client, protocol, iter->data() );
	}
}

void Packet_System::SendPacket( PSocketContext client, std::vector<flatbuffers::Offset<Packet>>& packets )
{
	flatbuffers::FlatBufferBuilder builder( 4096 );
	auto clientProtocol = CreateProtocol( builder, builder.CreateString("Server"), EServer_MIN, 0, builder.CreateVector(packets));
	builder.Finish( clientProtocol );

	//Socket_System::GetInstance().Send( client, builder.GetBufferPointer() );
}

void Packet_System::BroadcastPacket( std::stringstream& sendPacket)
{
	//TH_SERVER::TH_PACKET dataPacket;
	//auto packet = dataPacket.add_packet();

	//packet->set_packettype( TH_SERVER::PACKET_TYPE::CHAT );
	//std::string temp = sendPacket.str();
	//packet->set_packetdata(temp);

	//char* sendBuffer = new char[4096];
	//dataPacket.SerializeToArray( sendBuffer, 4096 );

	//Socket_System::GetInstance().Broadcast( sendBuffer );
}

void Packet_System::Broadcast_Server_Packet()
{
}

void Packet_System::Login_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet )
{
	auto data = (LOGIN_DATA*) packet;

	bool TokenCheck = Database_System::GetInstance().Token_Verify( protocol->clientid()->str(), data->token()->str() );
	if ( TokenCheck == false )
	{
		return;
	}

	flatbuffers::FlatBufferBuilder builder( 4096 );
	//builder.Reset();

	auto ClientPacket = CreatePacket( builder, PacketData_LOGIN, builder.CreateString("Login").o);

	std::vector<flatbuffers::Offset<Packet>> packets;
	packets.emplace_back( ClientPacket );


	auto clientProtocol = CreateProtocol( builder, builder.CreateString("Server"), EServer_MIN, 0, builder.CreateVector(packets));
	builder.Finish( clientProtocol );

	Socket_System::GetInstance().Send( client, builder.GetBufferPointer(), builder.GetSize() );

	builder.Release();

	//GetInstance().SendPacket( client, packets );
	//Game_System::GetInstance().Add_Player_In_Server();
}

void Packet_System::Chat_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet )
{
	auto data = (CHAT_DATA*) packet;
}

void Packet_System::Player_PacketProcess(PSocketContext client, const Protocol* protocol, const void* packet)
{
	auto data = (PLAYER_DATA*)packet;

	auto player = Game_System::GetInstance().Get_Player( protocol->server(), protocol->channel(), protocol->clientid()->str() );

	player._position = *data->position();

	Packet_System::GetInstance().Make_Player_Packet( player );
}

void Packet_System::Make_Player_Packet( Player& player )
{
	auto data = CreatePLAYER_DATA( _serverBuilder, _serverBuilder.CreateString(player._ClientID), player._NetworkID, &player._position);

	auto playerPacket = CreatePacket( _serverBuilder, PacketData_PLAYER, data.o );

	_serverPackets.emplace_back( playerPacket );
}

