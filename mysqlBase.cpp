#include "mysqlBase.h"

/*
*/
mysqlBase::mysqlBase()
{
	Json::Value root;
        Json::Reader reader;
        //string cfgs[] = {"IP","Port", "User", "Pass"};
	ifstream ifs("./cmaConfig.json");
        string json_file(
                (istreambuf_iterator<char>(ifs)),
                (istreambuf_iterator<char>())
                );
        //cout << "TEST = " << json_file << endl << endl;
        bool parsedSuccess = reader.parse(json_file, root, false);
        if(not parsedSuccess)
        {
                // Report failures and their locations
                // in the document.
                cout<<"Failed to parse JSON"<<endl
                        <<reader.getFormatedErrorMessages()
                        <<endl;
               return; 
        }
	
	ip = root["IP"].asString();
	port = root["Port"].asString();
	user = root["User"].asString();
	pass = root["Pass"].asString();

}
/*
*/
void mysqlBase::printDBs()
{
	res = stmt->executeQuery("show databases");
	while (res->next()) {
		cout << "<tr><td>" << res->getString(1) << "</td></tr>" << endl;
  	}	
	delete res;
  	delete stmt;
  	delete con;
}
/*
*/
void mysqlBase::printTables()
{
	con->setSchema("test");
	res = stmt->executeQuery("show tables");
        while (res->next()) {
                cout << "<tr><td>" << res->getString(1) << "</td></tr>" << endl;
        }
        delete res;
        delete stmt;
        delete con;
}
/*
*/
bool mysqlBase::executeQuery(const string query)
{
	con->setSchema("test");
	res = stmt->executeQuery(query);
	mData = res->getMetaData();
	int numberOfColumns = mData->getColumnCount();
	//cout << numberOfColumns ;
	while (res->next()) {
		cout << "<tr>";
		for (int y=1; y <= numberOfColumns ; y++) {
			//cout << y;
			cout << "<td>" << res->getString(y) << "</td>" << endl;
		}
		cout << "</tr>";
  	}	
	delete res;
  	delete stmt;
  	delete con;
	return false;
}

/*
*/
bool mysqlBase::connect()
{
	//cout << ip << port << user << pass << endl;
	string mysqltarget = "tcp://" + ip + ":" + port;
	//cout << mysqltarget << endl;
	try {
		driver = sql::mysql::get_driver_instance();
		con = driver->connect(mysqltarget, user, pass);
		stmt = con->createStatement();
	} catch (sql::SQLException &e) {
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line "  \
			<< __LINE__ << endl;
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
	return false;
}
