#include "Database_System.h"

#include <iostream>

bool Database_System::Initialize()
{
	MYSQL* conn = new MYSQL();
	mysql_init( conn );

	const char* host = "localhost";
	const char* user = "TESTUSER";
	const char* passwd = "TESTUSER";
	const char* db = "TESTUSER";
	unsigned int port = 3306;

	_mysql = mysql_real_connect( conn, host, user, passwd, db, port, (char*) NULL, NULL );

	if ( _mysql == nullptr )
	{
		return false;
	}

	return true;
}

void Database_System::Tick()
{
}

void Database_System::Destroy()
{
	mysql_close( _mysql );
}

void Database_System::Token_Renewal( std::string clientId, std::string token )
{
	std::cout << "[Database_System] ClientID : " + clientId + " Token : " + token;
}

void Database_System::Token_Clear( std::string clientID )
{
}

bool Database_System::Token_Verify( std::string clientID, std::string token )
{
	return true;
}
