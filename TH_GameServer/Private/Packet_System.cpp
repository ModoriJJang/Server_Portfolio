#include "Packet_System.h"

#include "../Protobuf/Packet.pb.cc"

#include"Chat_System.h"
#include "Socket_System.h"


bool Packet_System::Initialize()
{
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
