#include <iostream>
#include "cgiBase.h"

using namespace std;
// my functions

void printFixed(cgiBase cb);
void printStyles(cgiBase cb);

int main ()
{
	cgiBase cb; 
	string Title = "Lava's MySql Admin Page";
	cb.printHeader(Title, "style");
	printStyles(cb);
	cb.sTag("body");
	printFixed(cb);
	cb.eTag("body");
	return 0;
}
