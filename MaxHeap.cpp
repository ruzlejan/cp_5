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
Node* MaxHeap::enroll(string courseName){

   
    if (root == nullptr) {
        return nullptr;
    }

    
    Node* maxNode = root;

    
    Node* lastNode = root;
    Node* parent = NULL;
    while (lastNode->right != NULL) {
        parent = lastNode;
        lastNode = lastNode->right;
    }
    if (lastNode->left != NULL) {
        lastNode = lastNode->left;
    }


    root->Bnum = lastNode->Bnum;
    root->course = lastNode->course;
    root->points = lastNode->points;

 
    if (parent != NULL) {
        parent->right = NULL;
    } else {
        root = NULL;
    }

    delete lastNode;


    Node* currNode = root;
    while (currNode != NULL) {
        Node* maxChild = currNode;
        if (currNode->left != NULL && currNode->left->points > maxChild->points) {
            maxChild = currNode->left;
        }
        if (currNode->right != NULL && currNode->right->points > maxChild->points) {
            maxChild = currNode->right;
        }
        if (maxChild == currNode) {
            break;
        }
        
        swap(currNode->Bnum, maxChild->Bnum);
        swap(currNode->course, maxChild->course);
        swap(currNode->points, maxChild->points);
        currNode = maxChild;
    }

    maxNode->course = courseName;

    return maxNode;


}