CC = gcc
CFLAGS = -Wall -std=c++17  -ggdb 

test : pr_check
	./pr_check prereqs.txt

clean :
	-rm pr_check