#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>
#include "cgiBase.h"
#include "mysqlBase.h"

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

void printSettings(cgiBase cb)
{
	Json::Value root;
        Json::Reader reader;
	string cfgs[] = {"IP","Port", "User", "Pass"};

	cb.sTag("h1", "align=\"center\"");
	cout << "Mysql DB Settings" ;
	cb.eTag("h1");
	cb.sTag("table", "id=\"t04\" align=\"center\"");
	cb.printItem("tr", "<th>Item</th><th>Value</th>");
	//cb.sTag("form");
	
	//JSon Parcing 
	ifstream ifs("./cmaConfig.json");
        string json_file(
                (istreambuf_iterator<char>(ifs)),
                (istreambuf_iterator<char>())
                );
	//cout << "TEST = " << json_file << endl << endl;
        bool parsedSuccess = reader.parse(json_file, root, false);
	if(not parsedSuccess)
        {
                // Report failures and their locations
                // in the document.
                cout<<"Failed to parse JSON"<<endl
                        <<reader.getFormatedErrorMessages()
                        <<endl;
                return;
        }
	for (int y=0; y < 4; y++ ) {
		cb.sTag("tr");	
		cb.sTag("td");	
		cout << cfgs[y];
		cb.eTag("td");	
		cb.sTag("td");	
		cout << root[cfgs[y]];
		cb.eTag("td");	
		cb.eTag("tr");	
	}
	
	//cb.eTag("form");
    	cb.eTag("table");
	//cout << "Settings. !!" << endl;
}
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
void printTables(cgiBase cb)
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

void printQuery(cgiBase cb)
{
	cb.sTag("h1", "align=\"center\"");
        cout << "Enter Custom Query String" ;
        cb.eTag("h1");
	cb.sTag("form", "name=\"input\" action=\"./mysqlAdmin.cgi?opt=dd\" method=\"get\"");
	cout << "Query: <input type=\"text\" name=\"query\" size=\"100\" >" << endl;
	cout << "<input type=\"submit\" value=\"Submit\"> " << endl;
	cb.eTag("form");
	//cout << "Custom Query !!" << endl;
}
