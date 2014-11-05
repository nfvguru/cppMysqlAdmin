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

void mysqlAdmin::updateSettings(cgiBase cb)
{
	cb.saveSettings();
	printSettings(cb);

}

void mysqlAdmin::printSettings(cgiBase cb)
{
	Json::Value root;
        Json::Reader reader;
	string cfgs[] = {"IP","Port", "User", "Pass"};

	cb.sTag("h1", "align=\"center\"");
	cout << "Mysql DB Settings";
	cb.eTag("h1");
	cb.sTag("table", "id=\"t04\" align=\"center\"");
	cb.sTag("form", "name=\"input\" action=\"./mysqlAdmin.cgi?opt=process\" method=\"post\"");
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
		cb.sTag("td", "width=\"50%\"");	
		cout << cfgs[y];
		cb.eTag("td");	
		cb.sTag("td", "width=\"50%\"");	
		if ( choice == 5 ) {
			cout << "<input type=\"text\" name=\"" << cfgs[y] << "\"  value=" << root[cfgs[y]] << " />";
		} else {
			cout << root[cfgs[y]];
		}
		cb.eTag("td");	
		cb.eTag("tr");	
	}
	
	cb.sTag("tr");
	//cb.sTag("form");
		cb.sTag("td", "valign=\"middle\" align=\"center\" colspan=\"2\" bgcolor=\"#abcdef\" ");
	if ( choice == 5 ) {
		cout << "<input type=\"hidden\" name=\"opt\" value=\"ssc\" />" << endl;
		cout << "<input type=\"submit\" value=\" Save \" align=\"center\" />" << endl;
		cout << "<input type=\"submit\" value=\" Cancel \" align=\"center\" />" << endl;
		cb.eTag("td");
	} else {
		cout << "<input type=\"hidden\" name=\"opt\" value=\"sse\" />" << endl;
		cout << "<input type=\"submit\" value=\"..Edit Settings..\" align=\"center\" />" << endl;
	}
	cb.eTag("td");
	cb.eTag("form");
	cb.eTag("tr");
    	cb.eTag("table");
	//cout << "Settings. !!" << endl;
}


