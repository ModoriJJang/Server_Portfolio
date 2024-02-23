#include "gRPC_System.h"




bool gRPC_System::Initialize()
{
    std::string server_address { "localhost:2511" };

    grpc::ServerBuilder builder;

    builder.AddListeningPort( server_address, grpc::InsecureServerCredentials() );
    builder.RegisterService( _service );

    _queue = builder.AddCompletionQueue();
    _server = builder.BuildAndStart();
    _server->Wait();
    return false;
}

void gRPC_System::Tick()
{
}

void gRPC_System::Destroy()
{
    _server->Shutdown();
    _queue->Shutdown();
}
