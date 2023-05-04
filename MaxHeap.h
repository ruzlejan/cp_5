#ifndef MAXHEAP_H
#define MAXHEAP_H
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class MaxHeap{
    private:
    Node* root;
    string courseName;


    public:
    MaxHeap(string courseName);
    string getCourseName();
    void add(string Bnum,string course,int points);
    void promote(string Bnum,int points);
    Node* enroll();
    Node* search(string Bnum);
    Node* searchHelper(Node* node, string Bnum);
   
    void printHeap();
     //extract max and return the name of the student
};



#endif