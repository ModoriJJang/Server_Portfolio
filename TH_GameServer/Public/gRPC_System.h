#pragma once

#include "../Protobuf/Packet.grpc.pb.h"
#include <grpc++/grpc++.h>

class gRPC_Login final : public TH_SERVER::RPC_System::AsyncService
{
	grpc::Status RPC_Login( grpc::ServerContext* context, const TH_SERVER::Login_Send* request,
		TH_SERVER::Login_Recv* reply ) override
	{
		printf( "grpc 테스트 성공" );
		return grpc::Status::OK;
	}
};

class gRPC_System
{

private: class CallData
{
public:
	CallData( TH_SERVER::RPC_System::AsyncService* service, grpc::ServerCompletionQueue* queue )
		: _service( service ), _queue( queue ), _response( &_context ), _status( CREATE )
	{
		// Invoke the serving logic right away.
		printf( "CallData 생성" );
		Proceed();
	}
public:
	void Proceed()
	{
		if ( _status == CREATE )
		{
			// Make this instance progress to the PROCESS state.
			_status = PROCESS;

			// As part of the initial CREATE state, we *request* that the system
			// start processing SayHello requests. In this request, "this" acts are
			// the tag uniquely identifying the request (so that different CallData
			// instances can serve different requests concurrently), in this case
			// the memory address of this CallData instance.
			_service->RequestRPC_Login( &_context, &_send, &_response, _queue, _queue, this );
		}
		else if ( _status == PROCESS )
		{
			// Spawn a new CallData instance to serve new clients while we process
			// the one for this CallData. The instance will deallocate itself as
			// part of its FINISH state.
			new CallData( _service, _queue );

			// The actual processing.
			_recv.set_message( "test" );

			// And we are done! Let the gRPC runtime know we've finished, using the
			// memory address of this instance as the uniquely identifying tag for
			// the event.
			_status = FINISH;
			_response.Finish( _recv, grpc::Status::OK, this );
			printf( "grpc 성공" );
		}
		else
		{
			// Once in the FINISH state, deallocate ourselves (CallData).
			printf( "grpc 삭제" );
			delete this;
		}
	}
private:
	grpc::ServerContext _context;
	grpc::ServerCompletionQueue* _queue;
	TH_SERVER::RPC_System::AsyncService* _service;
	TH_SERVER::Login_Send _send;
	TH_SERVER::Login_Recv _recv;

	grpc::ServerAsyncResponseWriter<TH_SERVER::Login_Recv> _response;
	enum CallStatus
	{
		CREATE,
		PROCESS,
		FINISH
	};
	CallStatus _status;

};
public:
	static gRPC_System& GetInstance()
	{
		static gRPC_System instance;
		return instance;
	}

public:
	bool Initialize();
	void Tick();
	void Destroy();

private:
	class gRPC_Login _service;
	std::unique_ptr<grpc::ServerCompletionQueue> _queue;
	std::unique_ptr<grpc::Server> _server;
	gpr_timespec _deadline;
	void* _tag = nullptr;
	bool _ok = false;
};



