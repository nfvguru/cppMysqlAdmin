#include <cgicc/CgiDefs.h>
#include <cgicc/Cgicc.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>

#ifndef GGIBASE_H
#define GGIBASE_H

#define CONTENT_TYPE "Content-type:text/html\r\n\r\n"

using namespace cgicc;
using namespace std;

class cgiBase 
{

private:
   Cgicc formData;
   void printTitle(const string title);

public:

   // my member functions
   void sTag(const string tag, const string options );
   void sTag(const string tag);
   void eTag(const string tag);
   void printHeader(const string title);
   void printHeader(const string title, const string hoptions);
   void printItem(const string tag, const string contents);

};

#endif // GGIBASE_H
