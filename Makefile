
CPP=g++
CPPFLAGS=-g -Wall
LDFLAGS=-lmysqlcppconn -lcgicc -ljsoncpp
CPP_INCLUDE=-I /usr/local/include 
CPP_LIBS=-L /usr/local/lib

OBJECTS=mysqlBase.o cgiBase.o mysqlAdmin.o index.o styles.o
SOURCE=mysqlBase.cpp cgiBase.cpp mysqlAdmin.cpp index.cpp styles.cpp

mysqlAdmin.cgi: $(OBJECTS)
	$(CPP) $(CPPFLAGS) $(CPP_INCLUDE) $(CPP_LIBS) $(OBJECTS) -o mysqlAdmin.cgi $(LDFLAGS)
	@sudo cp -dpRvf mysqlAdmin.cgi /usr/lib/cgi-bin

all:

.PHONY: clean
clean:
	rm -f *~ *.o mysqlAdmin.cgi

