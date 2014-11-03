#ifndef MYSQLADMIN_H
#define MYSQLADMIN_H

#define CONTENT_TYPE "Content-type:text/html\r\n\r\n"

using namespace std;

void printFixed(cgiBase cb);
void printDefault(cgiBase cb);
void printStyles(cgiBase cb);
void printBody(cgiBase cb, void (*callBack) (cgiBase cb));

#endif //  MYSQLADMIN_H
