#!/bin/sh
echo Hello #echo world
echo Hello #world
echo Hello #|| world && nice
echo Hello && echo world #|| world && nice
#echo Hello world
echo #Hello world
echo Hello && echo world #nice
echo Hello world #nice
ls #|| world && nice
ls -a # echo Hello world
cd .. #|| world && nice
ls #|| world && nice
mkdir testcase #|| world && nice
ls #|| world && nice
test -e testcase #|| world && nice
[ -e testcase ] #|| world && nice
test -f testcase #|| world && nice
[ -f testcase ] #|| world && nice
test -d testcase #|| world && nice
[ -d testcase ] #|| world && nice
test -e null #|| world && nice
[ -e null ] #|| world && nice
test -f testcase #|| world && nice
[ -f null ] #|| world && nice
test -d null #|| world && nice
[ -d null ] #|| world && nice
ls || (echo Hellow && echo world || nice) #|| world && nice
ls || (echo Hellow && echo world && nice) #|| world && nice
ls || (echo Hellow && echo world && ls -a) #|| world && nice
exit #|| world && nice
