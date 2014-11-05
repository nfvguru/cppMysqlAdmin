#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#include "cgiBase.h"
using namespace cgicc;


/*
*/
void cgiBase::printHeader(const string title, const string hoptions) 
{
	cout << CONTENT_TYPE << endl;	
	sTag("html");
	sTag("head");
	printTitle(title);
	sTag(hoptions);
}

/*
*/
void cgiBase::printHeader(const string title) 
{
	cout << CONTENT_TYPE << endl;	
	sTag("html");
	sTag("head");
	printTitle(title);
	eTag("head");
}

/*
*/
void cgiBase::sTag(const string tag)
{
	cout << "<" << tag <<  ">" ;
}

/*
*/
void cgiBase::sTag(const string tag, const string options)
{
	cout << "<" << tag << " " << options <<  ">" ;
}


/*
*/
void cgiBase::eTag(const string tag)
{
	cout << "</" << tag << ">" << endl;
}

/*
*/
void cgiBase::printTitle(const string title)
{
	sTag("title");
	cout << title;
	eTag("title");
	
}

/*
*/
void cgiBase::printItem(const string tag, const string contents)
{
	sTag(tag);
	cout << contents;
	eTag(tag);
}

/*
*/
void cgiBase::printUrl (const string text, const string url)
{
	cout << "<a href=\"" << url << "\">" << endl;
	cout << text;
	eTag("a");

}

/*
*/
bool cgiBase::isElement(const string element, const string value)
{
	try {
		form_iterator fi = formData.getElement(element);
		if( !fi->isEmpty() && fi != (*formData).end()) {  
			string curval= **fi;
			if ( curval.compare(value) == 0 ) {
				return true;
			}    
		}
	} catch (...) {
		cout << "Exception in parsing the query string !!";
	}
	return false;
}

/*
*/
int cgiBase::getOption()
{
	string links[] = {"set", "mdb", "mtb", "cqs", "pq1" };
	int arrSize = sizeof(links)/sizeof(links[0]);
        for ( int y =0; y < arrSize; y++)
        {
		if (isElement("opt", links[y])) return y;
	}
	return 100;
}

