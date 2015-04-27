CC = g++
FLAGS = -Wall -pedantic -Werror -std=c++14
LIBS = -lpthread -lwiringPi -lrt

SOURCES = ExternalCommand.cpp
HEADERS = ExternalCommand.h
FILE = ExternalCommand.o

all : $(FILE)

$(FILE) : $(SOURCES) $(HEADERS)
	$(CC) $(SOURCES) $(FLAGS) $(LIBS) -c -o $(FILE)

clean :
	rm -f $(FILE)