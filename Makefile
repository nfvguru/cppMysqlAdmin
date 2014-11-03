
CPP=g++
CPPFLAGS=-g -Wall
LDFLAGS=-lmysqlcppconn -lcgicc

OBJECTS=mysqlBase.o cgiBase.o mysqlAdmin.o index.o styles.o
SOURCE=mysqlBase.cpp cgiBase.cpp mysqlAdmin.cpp index.cpp styles.cpp

mysqlAdmin.cgi: $(OBJECTS)
	$(CPP) $(CPPFLAGS) $(OBJECTS) -o mysqlAdmin.cgi $(LDFLAGS)
	@sudo cp -dpRvf mysqlAdmin.cgi /usr/lib/cgi-bin

all:

.PHONY: clean
clean:
	rm -f *~ *.o mysqlAdmin.cgi

