#pragma once

#include <string>
class Player
{
public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	std::string _ID;
};

