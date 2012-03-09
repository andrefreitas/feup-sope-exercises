#!/bin/bash
gcc -o copy1 prob2a.c
gcc -o copy2 prob2b.c

# creating a big file
for i in {1..131072}
do
	echo "a" >> stone.txt
done
#benchmarking
echo "using fopen(), fwrite() and fclose()"
time ./copy1 stone.txt dest.txt
echo " "
echo "using open(), write() and close()"
time ./copy2 stone.txt dest2.txt

# clean up
rm stone.txt
rm dest.txt
rm dest2.txt
rm copy1
rm copy2
