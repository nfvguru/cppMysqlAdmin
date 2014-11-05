#ifndef MYSQLADMIN_H
#define MYSQLADMIN_H

#define CONTENT_TYPE "Content-type:text/html\r\n\r\n"

using namespace std;

class mysqlAdmin
{
	public:
		void show();
		int choice;
	private:
		void printFixed(cgiBase cb);
		void printStyles(cgiBase cb);
		void printLeft(cgiBase cb);
		void printBody(cgiBase cb, void (mysqlAdmin::*callBack) (cgiBase cb));
		void printDefault(cgiBase cb);
		void printSettings(cgiBase cb);
		void printDB(cgiBase cb);
		void printTables(cgiBase cb);
		void printQuery(cgiBase cb);
		void doQuery(cgiBase cb);
		void updateSettings (cgiBase cb);
};
#endif //  MYSQLADMIN_H
