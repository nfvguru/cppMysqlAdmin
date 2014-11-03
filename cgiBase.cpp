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
