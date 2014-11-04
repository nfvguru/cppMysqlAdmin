#include <iostream>
#include "cgiBase.h"
#include "mysqlAdmin.h"

using namespace std;
// my functions

/*
void printFixed(cgiBase cb);
void printStyles(cgiBase cb);
void printBody(cgiBase cb, void (*callBack) (cgiBase cb));
*/

int main ()
{
	cgiBase cb; 
	//void (*contentFunc) (cgiBase cb);
	
	string Title = "Lava's MySql Admin Page";
	cb.printHeader(Title, "style");
	printStyles(cb);
	cb.sTag("body");
	printFixed(cb);
	//check if any Query String Available
	string qs= getenv("QUERY_STRING") ;
	if ( qs.find("opt=") == std::string::npos )
		//if opt is not available , print default
		printBody(cb, printDefault);
	else 
	{
		//swtich as per opt	
		int opt = cb.getOption();
		switch (opt) 
		{
			case 0:
				//settings
				printBody(cb, printSettings);
				break;

			case 1:
				//manage DB
				printBody(cb, printDB);
				break;

			case 2:
				//manage Tables
				printBody(cb, printTables);
				break;

			case 3:
				//Custom Query
				printBody(cb, printQuery);
				break;
			default:
				//default page
				printBody(cb, printDefault);
				break;

		}
	}
	cb.eTag("body");
	return 0;
}
