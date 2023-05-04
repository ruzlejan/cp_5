#ifndef NODE_H
#define NODE_H
#include <string>

using namespace std;

class Node{
    private:
    string Bnum;
    string course;
    int points;
    Node* left;
    Node* right;
    Node* parent;

    public:
    Node(string Bnum,string course,int points);
    string getBnum();
    string getCourse();
    int getPoints();


      friend class MaxHeap; 
};

#endif