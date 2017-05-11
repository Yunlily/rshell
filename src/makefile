all: rshell

rshell: main.o Cmd.o Connector.o 
	g++ main.o Cmd.o Connector.o -Wall -Werror -ansi -pedantic
	
main.o: main.cpp
	g++ -c main.cpp
	
Cmd.o: Cmd.cpp
	g++ -c Cmd.cpp

Connector.o: Connector.cpp
	g++ -c Connector.cpp

clean: 
	rm main.o Cmd.o Connector.o 
	
