#pragma once
#include <unordered_map>
#include <sstream>

class Chat_System
{
	public:
	static Chat_System& GetInstance()
	{
		static Chat_System instance;
		return instance;
	}

public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	void Chat(std::string channel, std::string chat);

private:
	std::unordered_map<std::string, std::stringstream*> _chatChannel;
};

