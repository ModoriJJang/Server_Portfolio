
#include "Packet_System.h"

#include <flatbuffers/flatbuffers.h>
#include "../FlatBuffers/GamePacket_generated.h"

#include "../Protobuf/Packet.pb.cc"

#include"Chat_System.h"
#include "Socket_System.h"

#include <vector>

using namespace TH_Server::TH_Packet;

bool Packet_System::Initialize()
{
	flatbuffers::FlatBufferBuilder builder( 4096 );
	auto packet1 = CreatePacket( builder, PacketData_LOGIN, CreateLOGIN_DATA(builder, builder.CreateString("token1")).Union());
	auto packet2 = CreatePacket( builder, PacketData_LOGIN, CreateLOGIN_DATA(builder, builder.CreateString("token2")).Union());

	std::vector<flatbuffers::Offset<Packet>> packets;
	packets.emplace_back(packet1);
	packets.emplace_back(packet2);


	auto protocol = CreateProtocol( builder, builder.CreateString("test"), Server_Server_1, 1, builder.CreateVector(packets).o	);
	builder.Finish( protocol );

	auto data = builder.GetBufferPointer();

	auto temp = GetProtocol( data );
	auto test = temp->packet()->Get( 0 );

	for ( auto it = temp->packet()->begin(); it != temp->packet()->end(); it++ )
	{
		if ( it->data_type() == PacketData_LOGIN )
		{
			std::string token = it->data_as_LOGIN()->token()->str();
			int a = 0;
		}
	}
	
	return false;
}

void Packet_System::Tick()
{
}

void Packet_System::Destroy()
{
}

void Packet_System::ReceivePacket(char* recvPacket)
{
	TH_SERVER::TH_PACKET dataPacket;
	dataPacket.ParseFromArray(recvPacket, 4096);

	std::string client = dataPacket.clientid();

	for ( auto& packet : dataPacket.packet() )
	{
		switch ( packet.packettype() )
		{
		case TH_SERVER::PACKET_TYPE::CHAT:
			Chat_System::GetInstance().Chat( "123123", packet.packetdata());
			break;
		case TH_SERVER::PACKET_TYPE::PLAYER:
			break;
		case TH_SERVER::PACKET_TYPE::MONSTER:
			break;
		default:
			break;
		}
	}
}

void Packet_System::SendPacket( char* sendPacket )
{
}

void Packet_System::BroadcastPacket( std::stringstream& sendPacket)
{
	TH_SERVER::TH_PACKET dataPacket;
	auto packet = dataPacket.add_packet();

	packet->set_packettype( TH_SERVER::PACKET_TYPE::CHAT );
	std::string temp = sendPacket.str();
	packet->set_packetdata(temp);

	char* sendBuffer = new char[4096];
	dataPacket.SerializeToArray( sendBuffer, 4096 );

	Socket_System::GetInstance().Broadcast( sendBuffer );
}
