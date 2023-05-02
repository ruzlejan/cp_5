#include "MaxHeap.h"
#include <iostream>

using namespace std;

MaxHeap::MaxHeap(string courseName){
    this->courseName = courseName;
    root = NULL;
}

string MaxHeap::getCourseName(){
    return this-> courseName;
}

void MaxHeap::add(string Bnum,string course,int points){
    Node* node = new Node(Bnum,course,points);
    //do the  insert function

    if(root == NULL){
        root = node;      
        return;
    }

    
}

//extract Max
string MaxHeap::enroll(string courseName){

}