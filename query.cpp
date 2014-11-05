#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>
#include "cgiBase.h"
#include "mysqlBase.h"

using namespace std;
void printQuery(cgiBase cb)
{
	cb.sTag("h1", "align=\"center\"");
        cout << "Enter Custom Query String" ;
        cb.eTag("h1");
	cb.sTag("form", "name=\"input\" action=\"./mysqlAdmin.cgi?opt=dd\" method=\"get\"");
	cout << "Query: <input type=\"text\" name=\"query\" size=\"100\" >" << endl;
	cout << "<input type=\"hidden\" name=\"opt\" value=\"pq1\"> " << endl;
	cout << "<input type=\"submit\" value=\"Submit\"> " << endl;
	cb.eTag("form");
	//cout << "Custom Query !!" << endl;
}

void doQuery(cgiBase cb)
{
	cout <<  "I will execute it .. be cool...." << endl;
}
