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
	void Token_Renewal( std::string clientId, std::string token );
	void Token_Clear( std::string clientID );
	bool Token_Verify( std::string clientID, std::string token );
	
private:
	MYSQL* _mysql = nullptr;
};

