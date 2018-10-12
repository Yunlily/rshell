**

RSHELL
------

**

Licensing information:
----------------------

Project source can be downloaded at 
https://github.com/Yunlily/rshell.git

Author and contribution list: Tianhang Zhang & Yun Li

All bug reports can be sent to tzhan028@ucr.edu and yli132@ucr.edu

How to run the program: run the following lines in terminal: 

git clone https://github.com/Yunlily/rshell.git

cd rshell

make

bin/rshell

Summary:
--------

rshell attempts to mimic a bash terminal shell. rshell accepts bash command executables that exist in /bin

Functionality:
--------------

The newly updated rshell script allow the user to run the command using the keyword test and it should allow the user to use the symbolic version of the command. Test command should work with the connectors && and ||.
Added the function so that the rshell can deal with cat < file | tr a-z A-Z | cat > file2

Bugs:
-----
If the parenthesis is inside the parenthesis, the script will only execute the separate commands but will cause error when executing the connector.

Generally, the parenthesis function only deals with the test cases in the form (echo A && echo B) || (echo C && echo D)

