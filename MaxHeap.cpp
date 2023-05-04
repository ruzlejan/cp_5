#include "MaxHeap.h"
#include <iostream>
#include <queue>

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
        
        if(root == NULL){
            root = node;     
            return;
        }

        Node* current = root;
        Node* parent = NULL;

        while(current != NULL){
            parent = current;

            if(node->points > current->points){
                current = current->right;
            }else{
                current = current->left;
            }
        }

         // Insert the new node as the left or right child of the parent node
         if(node->points > parent->points){
            parent->right = node;
         }else{
            parent->left = node;
         }

         // Set the new node's parent pointer
         node->parent = parent;

         // Rebalance the heap by swapping the new node with its parent as necessary
         while(node->parent != NULL && node->points > node->parent->points){
            swap(node->points, node->parent->points);
             swap(node->course, node->parent->course);
            swap(node->Bnum,node->parent->Bnum);
            node = node->parent;
         }

        }

    void MaxHeap::printHeap() {
    if (root == NULL) {
        cout << "Heap is empty." << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            cout << "(" << curr->Bnum << ", " << curr->course << ", " << curr->points << ") ";
            if (curr->left != NULL) {
                q.push(curr->left);
            }
            if (curr->right != NULL) {
                q.push(curr->right);
            }
        }
        cout << endl;
    }

    cout << endl;
}




    

//extract Max
Node* MaxHeap::enroll(){

   
    if (root == NULL) {
        return NULL;
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

   Node* node = search(bNum);
    if (node == NULL) {
        return; // Bnum not found in the heap
    }
    // Update the node's points
    node->points = points;
    // Rebuild the heap by swapping the node with its parent if it is greater than its parent
    while (node->parent != NULL && node->points > node->parent->points) {
           swap(node->points, node->parent->points);
             swap(node->course, node->parent->course);
            swap(node->Bnum,node->parent->Bnum);
        node = node->parent;
    }
    
}

Node* MaxHeap::search(string bNum){

return searchHelper(this->root,bNum);
    
}

Node* MaxHeap::searchHelper(Node* node, string Bnum){
 if (node == NULL) {
        return NULL;
    }
    if (node->Bnum == Bnum) {
        return node;
    }
    Node* leftResult = searchHelper(node->left, Bnum);
    if (leftResult != NULL) {
        return leftResult;
    }
    Node* rightResult = searchHelper(node->right, Bnum);
    if (rightResult != NULL) {
        return rightResult;
    }
    return NULL;
}