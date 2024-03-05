#include "gRPC_System.h"

#include "../Protobuf/Packet.pb.cc"
#include "../Protobuf/Packet.grpc.pb.cc"

bool gRPC_System::Initialize()
{
	std::string server_address { "localhost:9876" };
	grpc::ServerBuilder builder;



	builder.AddListeningPort( server_address, grpc::InsecureServerCredentials() );
	builder.RegisterService( &_service );

	_queue = builder.AddCompletionQueue();
	_server = builder.BuildAndStart();

	//grpc::ServerContext context;
	//TH_SERVER::Login_Send send;
	//grpc::ServerAsyncResponseWriter<TH_SERVER::Login_Recv> recv( &context );
	//_service.RequestRPC_Login( &context, &send, &recv , _queue.get(), _queue.get(), (void*) 1);

	_deadline = gpr_time_add(gpr_now(GPR_CLOCK_MONOTONIC), gpr_time_from_millis(0, GPR_TIMESPAN));
	new CallData( &_service, _queue.get() );

	return false;
}

void gRPC_System::Tick()
{
	_queue->AsyncNext( &_tag, &_ok, _deadline );

	if ( _tag != nullptr )
	{
		static_cast<CallData*>( _tag )->Proceed();
		_tag = nullptr;
		_ok = false;
	}
}

void gRPC_System::Destroy()
{
	_server->Shutdown();
	_queue->Shutdown();
}