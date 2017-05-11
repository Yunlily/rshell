**Author**
------

CS100

Assignment 2

Tianhang Zhang	

Yun Li

**Files**
-----


main.cpp
Connector.cpp
Connector.h
Cmd.cpp
Cmd.h
Base.h

**Introduction**
---------------
use the following commands to compile:
git clone  https://github.com/Yunlily/rshell.git
cd rshell
git checkout hw2
make
bin/rshell

When executed, this program will prompt the user with the usual '$' prompt to enter commands. And then it takes in the user inputs and pass them into the arguments to parse and execute them.

The command exit will prompt the program to exit.

**Class Specific Details**
----------------------

There are 3 classes in this program, a base class "Base",  a class named Connector and a class named Cmd. Also, the main function will ensure the smooth running of the program using these three classes.

The main objective for the Base class is to set up the interface with a pure virtual function execute that the other classes use. 

The Cmd class is in charge of parsing the user inputs and execute the arguments after parsing. It also uses the class Connector when parsing because it needs to discern "and" and "or" arguments and treat them separately from the other commands.

The Connector class mainly deals with the connectors of "and" and "or".

The Both class has a left and a right child and always executes both the left and right children.

**Bugs**
----

The program Can’t deal with Command whose length is more than the max_size of c++11 string: 4294967291
It also can’t Deal with multiple command input starting with operators and containing &&, the logic error may occur.