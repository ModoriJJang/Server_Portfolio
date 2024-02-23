#pragma once

#include <mysql/mysql.h>

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

private:
	MYSQL* _mysql = nullptr;
};

