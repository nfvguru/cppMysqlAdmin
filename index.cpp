#include <iostream>
#include "cgiBase.h"

using namespace std;
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
