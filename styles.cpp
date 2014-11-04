#include <iostream>
#include "cgiBase.h"

using namespace std;
void printStyles (cgiBase cb)
{
	//  Top Table
	const char * tableoptions1 = "table#t01 {\
        width: 100%;\
        background-color: #f1f1c1;\
        }";

	const char * tableoptions2 = "table#t02 {\
        width: 100%;\
	height: 90%;\
	border: 1px solid white;\
        background-color: #e1e1b1;\
        }\
	table#t02 th {\
	border: 1px solid white;\
	}";
	
	const char * tableoptions3 = "table#t03 {\
        width: 100%;\
        background-color: #f2f2c2;\
        }";

	const char * tableoptions4 = "table#t04 {\
        width: 60%;\
        background-color: #a2a2a2;\
	border: 1px solid white;\
        }\
	table#t04 td,th {\
	border: 1px solid blue;\
	}\
	";

	cout << tableoptions1 << endl;
	cout << tableoptions2 << endl;
	cout << tableoptions3 << endl;
	cout << tableoptions4 << endl;

	cb.eTag("style");
	cb.eTag("head");
}
