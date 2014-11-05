#include <iostream>
#include "cgiBase.h"
#include "mysqlAdmin.h"

using namespace std;

int main ()
{
	cgiBase cb; 
	//callback function to print the right body
	void (*callBack) (cgiBase cb);
	
	//check if any Query String Available
	string qs= getenv("QUERY_STRING") ;
	if ( qs.find("opt=") == std::string::npos )
		//if opt is not available , print default
		callBack = printDefault;
	else 
	{
		//swtich as per opt	
		int opt = cb.getOption();
		switch (opt) 
		{
			case 0:
				//settings
				callBack = printSettings;
				break;

			case 1:
				//manage DB
				callBack = printDB;
				break;

			case 2:
				//manage Tables
				callBack = printTables;
				break;

			case 3:
				//Custom Query
				callBack = printQuery;
				break;

			case 4:
				//manage Tables
				callBack = doQuery;
				break;

			default:
				//default page
				callBack = printDefault;
				break;

		}
	}

	/*
	THE ACTUAL CODE TO PRINT THE GUI
	*/
	string Title = "Lava's MySql Admin Page";
	cb.printHeader(Title, "style");
	printStyles(cb);
	cb.sTag("body");
	printFixed(cb);
	printBody(cb, callBack);
	cb.eTag("body");
	cb.eTag("html");
	return 0;
}
