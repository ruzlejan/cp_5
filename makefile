CC = g++
CFLAGS=-std=c++17 -Wall -Wextra -pedantic -O3

output: main.o MaxHeap.o Node.o pr_check.o sch_check.o
	g++ main.o MaxHeap.o Node.o pr_check.o sch_check.o -o main

main.o: main.cpp
	g++ -c main.cpp

pr_check.o: pr_check.cpp pr_check.h
	g++ -c pr_check.cpp	

sch_check.o: sch_check.cpp sch_check.h
	g++ -c sch_check.cpp

MaxHeap.o: MaxHeap.cpp MaxHeap.h
	g++ -c MaxHeap.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

waitlist.o: waitlist.cpp
	g++ -c waitlist.cpp

waitlist:waitlist.o  MaxHeap.o Node.o pr_check.o sch_check.o
	g++ waitlist.o MaxHeap.o Node.o pr_check.o sch_check.o -o waitlist
	./waitlist 2023Fall prerequisites.txt schedules.txt enroll.txt


testpr_check : pr_check
	./pr_check prereqs.txt

testsch_check : sch_check
	./sch_check prereqs.txt schedfile.txt

clean :	
	rm -f *.o waitlist main
	