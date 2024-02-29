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



	//flatbuffers::FlatBufferBuilder builder( 4096 );
	//auto packet1 = CreatePacket( builder, PacketData_LOGIN, CreateLOGIN_DATA(builder, builder.CreateString("token1")).Union());
	//auto packet2 = CreatePacket( builder, PacketData_LOGIN, CreateLOGIN_DATA(builder, builder.CreateString("token2")).Union());

	//std::vector<flatbuffers::Offset<Packet>> packets;
	//packets.emplace_back(packet1);
	//packets.emplace_back(packet2);


	//auto protocol = CreateProtocol( builder, builder.CreateString("test"), Server_Server_1, 1, builder.CreateVector(packets).o	);
	//builder.Finish( protocol );

	//auto data = builder.GetBufferPointer();

	/*auto temp = GetProtocol( data );
	auto test = temp->packet()->Get( 0 );

	for ( auto it = temp->packet()->begin(); it != temp->packet()->end(); it++ )
	{
		if ( it->data_type() == PacketData_LOGIN )
		{
			std::string token = it->data_as_LOGIN()->token()->str();
			int a = 0;
		}
	}*/
	/*{
		auto packets = GetProtocol( data )->packet();

		for ( auto iter = packets->begin(); iter != packets->end(); iter++ )
		{
			(*func_PacketProcess[iter->data_type()]) ( iter->data() );
		}
	}*/
	

	
	return false;
}

void Packet_System::Tick()
{
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

	Socket_System::GetInstance().Send( client, builder.GetBufferPointer() );
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

void Packet_System::Login_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet )
{
	auto data = (LOGIN_DATA*) packet;

	bool TokenCheck = Database_System::GetInstance().Token_Verify( protocol->clientid()->str(), data->token()->str() );
	if ( TokenCheck == false )
	{
		return;
	}

	flatbuffers::FlatBufferBuilder builder( 4096 );

	auto ClientPacket = CreatePacket( builder, PacketData_LOGIN, builder.CreateString("Login").o);

	std::vector<flatbuffers::Offset<Packet>> packets;
	packets.emplace_back( ClientPacket );


	auto clientProtocol = CreateProtocol( builder, builder.CreateString("Server"), EServer_MIN, 0, builder.CreateVector(packets));
	builder.Finish( clientProtocol );

	Socket_System::GetInstance().Send( client, builder.GetBufferPointer() );

	builder.Release();

	//GetInstance().SendPacket( client, packets );
	//Game_System::GetInstance().Add_Player_In_Server();
}

void Packet_System::Chat_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet )
{
	auto data = (CHAT_DATA*) packet;
}

void Packet_System::Player_PacketProcess( PSocketContext client, const Protocol* protocol, const void* packet )
{
	auto data = (PLAYER_DATA*) packet;
}
