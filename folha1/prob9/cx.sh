#!/bin/bash
file="$1.c"
rm -rf $1
rm -rf *.o

gcc -o $1 $file -Wall

if [[ $? -eq 0 ]]; then
        ./$1
else
	echo "Compilation Error!"
fi
