#include <iostream>
#include "cgiBase.h"
#include "mysqlAdmin.h"

using namespace std;

void mysqlAdmin::show()
{
	cgiBase cb; 
	//mysqlAdmin ma;

	int opt=0;
	//callback function to print the right body
	void (mysqlAdmin::*callBack) (cgiBase cb);
	
	//check if any Query String Available
	string qs= getenv("QUERY_STRING") ;
	if ( qs.find("opt=") == std::string::npos )
		//if opt is not available , print default
		callBack = &mysqlAdmin::printDefault;
	else 
	{
		//swtich as per opt	
		opt = cb.getOption();
		switch (opt) 
		{
			case 0:
			case 5:
				//settings
				callBack = &mysqlAdmin::printSettings;
				break;

			case 1:
				//manage DB
				callBack = &mysqlAdmin::printDB;
				break;

			case 2:
				//manage Tables
				callBack = &mysqlAdmin::printTables;
				break;

			case 3:
				//Custom Query
				callBack = &mysqlAdmin::printQuery;
				break;

			case 4:
				//manage Tables
				callBack = &mysqlAdmin::doQuery;
				break;

			case 6:
				//manage Tables
				callBack = &mysqlAdmin::updateSettings;
				break;

			default:
				//default page
				callBack = &mysqlAdmin::printDefault;
				break;

		}
	}

	choice = opt;
	/*
	THE ACTUAL CODE TO PRINT THE GUI
	*/
	string Title = "Lava's MySql Admin Page";
	cb.printHeader(Title, "style");
	printStyles(cb);
	cb.sTag("body");
	printFixed(cb);
	//cout << opt << "qs=" << qs << endl;
	cout << opt << endl;
	printBody(cb, callBack);
	cb.eTag("body");
	cb.eTag("html");
}

int main ()
{
	mysqlAdmin ma;
	ma.show();
	return 0;
}
