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
void mysqlAdmin::printLeft(cgiBase cb)
{
	string options[] = {"Settings", "Manage DBs", "Manage Tables", "Custom Query"};
	string links[] = {"set", "mdb", "mtb", "cqs" };

    	cb.sTag("table", "id=\"t03\"");
	int arrSize = sizeof(options)/sizeof(options[0]);
	for ( int y =0; y < arrSize; y++)
	{
		//
		cb.sTag("tr");
		cb.sTag("th");
		string link= "./mysqlAdmin.cgi?opt=" + links [y];
		cb.printUrl(options[y], link);
		cb.eTag("tr");
		cb.eTag("th");
	} 
	cb.eTag("table");
}

void mysqlAdmin::printFixed(cgiBase cb)
{
	cb.sTag("table", "id=\"t01\"");
	//cb.printItem("caption", "Mysql Admin");
	cb.sTag("tr");
	cb.sTag("th colspan=\"2\"");
	cb.printItem("h1", "Lavanz Mysql Admin");
	cb.eTag("th");
	cb.eTag("tr");
	cb.eTag("table");
}

void mysqlAdmin::printBody(cgiBase cb, void (mysqlAdmin::*callBack) (cgiBase cb)) 
{
    	cb.sTag("table", "id=\"t02\"");
	cb.sTag("tr");
	cb.sTag("th", "width=\"20%\" valign=\"top\"");
	printLeft(cb);
	cb.eTag("th");
	cb.sTag("th", "width=\"80%\"");
	(this->*callBack)(cb);
	cb.eTag("th");
	cb.eTag("tr");
    	cb.eTag("table");
}

void mysqlAdmin::printDefault(cgiBase cb)
{
	cout << "Welcome !!" << endl;
}

