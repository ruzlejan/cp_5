#include "Node.h"
#include <iostream>

using namespace std;

Node::Node(string Bnum, string course, int points) {
    this->Bnum = Bnum;
    this->course = course;
    this->points = points;
    left = NULL;
    right = NULL;
    parent = NULL;
}

string Node::getBnum(){
    return this->Bnum;
}

string Node::getCourse(){
    return this->course;
}

int Node::getPoints(){
    return this->points;
}