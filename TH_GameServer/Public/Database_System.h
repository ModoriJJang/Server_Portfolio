#pragma once

#include <mysql/mysql.h>

#include <string>

class Database_System
{
public:
	static Database_System& GetInstance()
	{
		static Database_System instance;
		return instance;
	}

public:
	bool Initialize();
	void Tick();
	void Destroy();

public:
	bool Token_Verify( std::string clientID, std::string token );

private:
	MYSQL* _mysql = nullptr;
};

