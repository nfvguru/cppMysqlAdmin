#include <iostream>
#include "cgiBase.h"

using namespace std;
void printStyles (cgiBase cb)
{
	const char * tableoptions = "table#t01 {\
        width: 100%;\
        background-color: #f1f1c1;\
        }";

	cout << tableoptions << endl;
	cb.eTag("style");
	cb.eTag("head");
}
