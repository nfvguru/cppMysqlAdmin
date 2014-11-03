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
	printBody(cb, printDefault);
	cb.eTag("body");
	return 0;
}
