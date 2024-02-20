#include "Packet_System.h"
#include "../Protobuf/Packet.pb.cc"
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

void Packet_System::PacketProcess( stringstream& recvPacket )
{
	TH_SERVER::TH_PACKET dataPacket;
	dataPacket.ParseFromIstream( &recvPacket );

	string client = dataPacket.clientid();
	int size = dataPacket.packet_size();

	TH_SERVER::PACKET_TYPE type = dataPacket.packet( 0 ).packettype();
	int a = 0;

	for ( auto& packet : dataPacket.packet() )
	{
		switch ( packet.packettype() )
		{
		case TH_SERVER::PACKET_TYPE::CHAT:
			packet.data();
			break;
		case TH_SERVER::PACKET_TYPE::PLAYER:
			a = 2;
			break;
		case TH_SERVER::PACKET_TYPE::MONSTER:
			break;
		default:
			break;
		}
	}
}
