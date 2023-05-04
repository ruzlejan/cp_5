CC = gcc
CFLAGS = -Wall -std=c++17  -ggdb 


main: main.o MaxHeap.o Node.o 
	g++ main.o MaxHeap.o Node.o -o main

main.o: main.cpp Node.h MaxHeap.h
	g++ -c main.cpp
MaxHeap.o: MaxHeap.cpp
	g++ -c MaxHeap.cpp

Node.o: Node.cpp 
	g++ -c Node.cpp

waitlist: waitlist.o  MaxHeap.o Node.o 
	g++ waitlist.o MaxHeap.o Node.o -o wait

waitlist.o: waitlist.cpp Node.h MaxHeap.h
	g++ -c waitlist.cpp


testpr_check : pr_check
	./pr_check prereqs.txt

testsch_check : sch_check
	./sch_check prereqs.txt schedfile.txt

clean :
	#rm sch_check
	rm -f *.o main