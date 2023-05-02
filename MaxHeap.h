#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <string>
#include "Node.h"

class MaxHeap{
    private:
    Node* root;
    string courseName;

    public:
    MaxHeap(string courseName);
    string getCourseName();
    void add(string Bnum,string course,int points);
    void promote(string Bnum,string course,int points);
    string enroll(string courseName);//extract max and return the name of the student
};



#endif