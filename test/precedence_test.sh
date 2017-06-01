#!/bin/sh
echo Hello; echo world; echo nice
(echo Hello && echo world) || (echo nice && echo work)
echo Hello; echo world && echo nice
cd .. || ls -a && mkdir testcase || pwd
((cd .. || ls -a ) && mkdir testcase) && pwd
ls && ((echo Hello || nice) || echo world)
ls && ((echo Hello && nice) || echo world)
ls && ((echo Hello && nice) || world)
ls && ((echo Hello && nice) && world)
(echo Hello && echo world) && test -e testcase
ls && (test -d temp/name.cc && echo m) || test -f temp/tinker
(cd .. || echo done) || exit
