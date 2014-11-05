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
void mysqlAdmin::printQuery(cgiBase cb)
{
	cb.sTag("h1", "align=\"center\"");
        cout << "Enter Custom Query String" ;
        cb.eTag("h1");
	cb.sTag("form", "name=\"input\" action=\"./mysqlAdmin.cgi?opt=process\" method=\"post\"");
	cout << "Query: <input type=\"text\" name=\"query\" size=\"100\" >" << endl;
	cout << "<input type=\"hidden\" name=\"opt\" value=\"pq1\"> " << endl;
	cout << "<input type=\"submit\" value=\"Submit\"> " << endl;
	cb.eTag("form");
	//cout << "Custom Query !!" << endl;
}

void mysqlAdmin::doQuery(cgiBase cb)
{
	mysqlBase mb;
        mb.connect();
	//cout <<  "I will execute it .. be cool....\nI know your query as " << endl;
	string query = cb.getQueryString("query");
	cb.sTag("h1", "align=\"center\"");
        cout << "Query Output" ;
        cb.eTag("h1");
        cout << "Current Database in use : test" ;
        cb.sTag("table", "id=\"t04\" align=\"center\"");
        mb.executeQuery(query);
        cb.eTag("table");
}

