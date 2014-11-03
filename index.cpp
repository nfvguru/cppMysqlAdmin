#include <iostream>
#include "cgiBase.h"

using namespace std;
void printLeft(cgiBase cb)
{
    	cb.sTag("table");
	cb.printItem("tr", "<th>settings</th>");
	cb.printItem("tr", "<th>Manage DBs</th>");
	cb.printItem("tr", "<th>Manage Tables</th>");
	cb.printItem("tr", "<th>Custom Query</th>");
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
    	cb.sTag("table");
	cb.sTag("tr");
	cb.sTag("th", "width:\"30%\"");
	printLeft(cb);
	cb.eTag("th");
	cb.sTag("th", "width:\"70%\"");
	callBack(cb);
	cb.eTag("th");
	cb.eTag("tr");
    	cb.eTag("table");
}

void printDefault(cgiBase cb)
{
	cout << "Welcome !!" << endl;
}
