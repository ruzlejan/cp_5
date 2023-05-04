#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <string>
#include "Node.h"

class MaxHeap{
    private:
    Node* root;
    string courseName;
    Node* search(string Bnum, Node* currNode);

    public:
    MaxHeap(string courseName);
    string getCourseName();
    void add(string Bnum,string course,int points);
    void promote(string Bnum,int points);
    Node* enroll();
    Node* search(string Bnum);
   
     //extract max and return the name of the student
};



#endif