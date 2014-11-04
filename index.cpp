#include <iostream>
#include "cgiBase.h"

using namespace std;
void printLeft(cgiBase cb)
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

void printFixed(cgiBase cb)
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

void printBody(cgiBase cb, void (*callBack) (cgiBase cb)) 
{
    	cb.sTag("table", "id=\"t02\"");
	cb.sTag("tr");
	cb.sTag("th", "width=\"20%\" valign=\"top\"");
	printLeft(cb);
	cb.eTag("th");
	cb.sTag("th", "width=\"80%\"");
	callBack(cb);
	cb.eTag("th");
	cb.eTag("tr");
    	cb.eTag("table");
}

void printDefault(cgiBase cb)
{
	cout << "Welcome !!" << endl;
}
