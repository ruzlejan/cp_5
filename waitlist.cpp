#include <iostream>
#include <sstream>
#include <cstring>
#include <unordered_map>
#include <string>
#include <vector>
#include "Node.h"
#include "MaxHeap.h"

using namespace std;


unordered_map<string,MaxHeap> course_map;
vector<string> str_vec;
string userLineInput;

string Bnum;
string course;
string points;

getline(cin,userLineInput);
stringstream ss(userLineInput);
while(ss >> userLineInput){
    str_vec.push_back(userLineInput);
}

while(str_vec.at(0) != "quit"){
    if((str_vec.at(0) == "newlist") && (str_vec.size() == 2)){
        course = str_vec.at(1)
        newlist(course);
        cout << "Course " << str_vec.at(1) << " created." << endl;
    }
    if((str_vec.at(0) == "add") && (str_vec.size() == 4)){
        Bnum = str_vec.at(1);
        course = str_vec.at(2);
        points = str_vec.at(3);
        course_map[course].add(Bnum,course,points);
    }
    if((str_vec.at(0) == "promote") && (str_vec.size() == 4)){
        Bnum = str_vec.at(1);
        course = str_vec.at(2);
        points = str_vec.at(3);
    }
    if((str_vec.at(0) == "enroll") && (str_vec.size() == 2)){
        course = str_vec.at(1);
        MaxHeap heapObj = course_map[course];
        Node* student = heapObj.enroll();
        string studentBnum = student.getBnum();

        //loop through all MaxHeap in the map. take off all the priority points 
        //of the student that was enrolled from other class
        

    }


    Bnum.clear();
    course.clear();
    points.clear();
    str_vec.clear();
       cout << endl;
    getline(cin, userLineInput);
    stringstream ss(userLineInput);
    while(ss >> userLineInput){
    str_vec.push_back(userLineInput);
    }


    if(str_vec.at(0) == "quit"){
        exit(0);
    }
}


void newlist(string courseName){
    MaxHeap heapObj = new MaxHeap(courseName);
    string name = heapObj.getCourseName();
    course_map[name] = heapObj;
}



