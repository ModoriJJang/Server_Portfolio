#pragma once

#include <grpc++/grpc++.h>

class gRPC_System
{
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
	grpc::Service* _service;
	std::unique_ptr<grpc::ServerCompletionQueue> _queue;
	std::unique_ptr<grpc::Server> _server;
};

