#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>
#include "cgiBase.h"
#include "mysqlBase.h"
#include "mysqlAdmin.h"

using namespace std;
void mysqlAdmin::printTables(cgiBase cb)
{
	mysqlBase mb;
	mb.connect();
	cb.sTag("h1", "align=\"center\"");
	cout << "Current List of Tables" ;
	cb.eTag("h1");
	cb.sTag("table", "id=\"t04\" align=\"center\"");
	cb.printItem("tr", "<th> Table Names </th>");
	mb.printTables();
	cb.eTag("table");
	//cout << "Manage Tables !!" << endl;
}

