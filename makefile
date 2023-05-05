CC = g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic -O3

main: main.o MaxHeap.o Node.o pr_check.o sch_check.o
	g++ main.o MaxHeap.o Node.o pr_check.o sch_check.o -o main

main.o: main.cpp Node.h MaxHeap.h pr_check.h sch_check.h
	g++ -c main.cpp

pr_check.o: pr_check.cpp
	g++ -c pr_check.cpp	

sch_check.o: sch_check.cpp
	g++ -c sch_check.cpp

MaxHeap.o: MaxHeap.cpp
	g++ -c MaxHeap.cpp

Node.o: Node.cpp 
	g++ -c Node.cpp


waitlist: waitlist.o  MaxHeap.o Node.o pr_check.o
	g++ waitlist.o MaxHeap.o Node.o pr_check.o -o waitlist

waitlist.o: waitlist.cpp Node.h MaxHeap.h pr_check.h
	g++ -c waitlist.cpp

testpr_check : pr_check
	./pr_check prereqs.txt

testsch_check : sch_check
	./sch_check prereqs.txt schedfile.txt

test: waitlist
	./waitlist 2023Fall prerequisites.txt 

clean :
	
	rm -f *.o main