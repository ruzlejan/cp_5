CC = gcc
CFLAGS = -Wall -std=c++17  -ggdb 

testpr_check : pr_check
	./pr_check prereqs.txt

testsch_check : sch_check
	./sch_check prereqs.txt schedfile.txt

clean :
	-rm sch_check