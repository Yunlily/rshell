#!/bin/sh
ls || exit
(ls || echo Hello) && echo world && exit
ls -a && (echo Hello && exit)
mkdir testcase
test -e testcase || exit
test -d testcase && exit
[ -f testcase ] || exit
[ -e testcase] && exit
ls -a && (echo Hello && exit)
(exit && echo Hello) || (echo world  && echo nice)
(echo Hello && echo world) || nice || exit
(echo Hello && echo world) && nice || exit
exit
