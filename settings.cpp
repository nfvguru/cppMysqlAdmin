#include <fstream>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <json/json.h>
#include "cgiBase.h"
#include "mysqlBase.h"

using namespace std;
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
