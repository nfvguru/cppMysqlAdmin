#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>

#include "mysql_connection.h"
#include "mysql_driver.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

#ifndef MYSQLBASE_H
#define MYSQLBASE_H


using namespace std;

class mysqlBase
{

private:
	string ip;
	string port;
	string user;
	string pass; 

	sql::mysql::MySQL_Driver *driver;
  	sql::Connection *con;
  	sql::Statement *stmt;
  	sql::ResultSet *res;
	sql::ResultSetMetaData *mData;

public:
	mysqlBase();
	void printDBs();	
	void printTables();
	bool executeQuery(const string query);
	bool connect();
	
};

#endif // MYSQLBASE_H
