#!/bin/sh
test -e /test/file/path
[ -e /test/file/path ]
test -f /test/file/path
[ -f /test/file/path ]
test -d /test/file/path
[ -d /test/file/path ]
test -e /test/file/path && echo Hello world
[ -e /test/file/path ] && echo Hello world
test -f /test/file/path && echo Hello world
[ -f /test/file/path ] && echo Hello world
test -d /test/file/path && echo Hello world
[ -d /test/file/path ] && echo Hello world
test -e /test/file/path || echo Hello world
[ -e /test/file/path ] || echo Hello world
test -f /test/file/path || echo Hello world
[ -f /test/file/path ] || echo Hello world
test -d /test/file/path || echo Hello world
[ -d /test/file/path ] || ls -a && echo Hello world
echo Hello world && ls -a || [ -d /test/file/path ]
echo Hello world && nice || ls -a
echo Hello world || nice && ls -a
ls -a && test -e /test/file/path || echo Hello world
exit
