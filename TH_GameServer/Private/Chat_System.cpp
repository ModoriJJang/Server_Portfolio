#include "Chat_System.h"

#include "Packet_System.h"

bool Chat_System::Initialize()
{
    return false;
}

void Chat_System::Tick()
{
}

void Chat_System::Destroy()
{
}

void Chat_System::Chat( std::string channel, std::string chat )
{
    auto iter = _chatChannel.find( channel );
    if ( iter == _chatChannel.end() )
    {
        std::stringstream* buffer = new std::stringstream();
        *buffer << chat + "\n";
        _chatChannel.insert( make_pair( channel, buffer ));


        Packet_System::GetInstance().BroadcastPacket( *buffer );
    }
    else
    {
        *(iter->second) << chat + "\n";
        Packet_System::GetInstance().BroadcastPacket( *( iter->second ) );
    }
}
