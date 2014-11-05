#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>
#include "cgiBase.h"
#include "mysqlBase.h"

using namespace std;
void printDB(cgiBase cb)
{
	mysqlBase mb;
	mb.connect();
	cb.sTag("h1", "align=\"center\"");
	cout << "Current List of DBs" ;
	cb.eTag("h1");
	cb.sTag("table", "id=\"t04\" align=\"center\"");
	cb.printItem("tr", "<th> Database Name </th>");
	mb.printDBs();
	cb.eTag("table");
	
}
