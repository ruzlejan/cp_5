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

   void MaxHeap::add(string Bnum,string course,int points){
        Node* node = new Node(Bnum,course,points);
        


        if(root == NULL){
            root = node;     
            return;
        }


        Node* current = root;
        Node* parent = NULL;


        if(current != NULL) {
            parent = current;


            if(node->points > current->points){
                current = current->right;


            }
            else{
                current = current->left;
            }
        }


        if(node->points -> current->points){
            parent->swapData(node);
        }


        while(parent->parent != NULL && parent->points > parent->parent->points){
            parent->swapData(parent->parent);
            parent = parent->parent;
        }




        
        }




    
}
//extract Max
Node* MaxHeap::enroll(){

   
    if (root == nullptr) {
        return nullptr;
    }

    // Store the maximum node
    Node* maxNode = root;

    // Find the last node of the heap
    Node* lastNode = root;
    Node* parent = NULL;
    while (lastNode->right != NULL) {
        parent = lastNode;
        lastNode = lastNode->right;
    }
    if (lastNode->left != NULL) {
        lastNode = lastNode->left;
    }

    // Replace the root node with the last node
    root->Bnum = lastNode->Bnum;
    root->course = lastNode->course;
    root->points = lastNode->points;

    // Remove the last node from the heap
    if (parent != NULL) {
        parent->right = NULL;
    } else {
        root = NULL;
    }
    delete lastNode;

    // Heapify the tree
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

    // Set the course name for the maximum node
    maxNode->course = courseName;

    // Return the maximum node
    return maxNode;
}

void MaxHeap::promote(string bNum,  int points) {


    
}

Node* MaxHeap::search(string bNum, Node* currNode) {

 if (currNode == nullptr) {
        return nullptr; 
    } else if (currNode->Bnum == bNum) {
        return currNode; 
    } else if (currNode->Bnum < bNum) {
        return nullptr; 
    } else {
        Node* leftResult = search(bNum, currNode->left); 
        if (leftResult != nullptr) {
            return leftResult; 
        } else {
            return search(bNum, currNode->right); 
        }
    }
}

Node* MaxHeap::search(string bNum) {

    return search(bNum, root);
}