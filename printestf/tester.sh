#!/bin/bash

rm -rf *.o && rm -rf myresults.txt && rm -rf rlresults.txt

echo "Enter your ft_printf directory"
read x
echo "Enter specifier to test against"
read y
if [ -d "$x" ]
then
	echo "Compiling your stuff with mine"
	gcc -c main.c && gcc -c "$x"/*.c && gcc -o tester *.o
	./tester "$y"
	echo "Return diff between your printf and the real one"
	diff myresults.txt rlresults.txt
else
	echo "Invalid directory"
fi
