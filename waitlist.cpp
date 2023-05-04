#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <vector>
#include "Node.h"
#include "MaxHeap.h"

using namespace std;

unordered_map<string, MaxHeap*> course_map;

void newlist(string courseName) {
    course_map[courseName] = new MaxHeap(courseName);
}

int main() {
    vector<string> str_vec;
    string userLineInput;

    string Bnum;
    string course;
    int points;

    cout << "Enter Command: ";
    getline(cin, userLineInput);
    stringstream ss(userLineInput);
    while (ss >> userLineInput) {
        str_vec.push_back(userLineInput);
    }

    while (str_vec.at(0) != "quit") {
        if ((str_vec.at(0) == "newlist") && (str_vec.size() == 2)) {
            course = str_vec.at(1);
            newlist(course);
            cout << "Course " << str_vec.at(1) << " created." << endl;
        }
        if ((str_vec.at(0) == "add") && (str_vec.size() == 4)) {
            Bnum = str_vec.at(1);
            course = str_vec.at(2);
            points = stoi(str_vec.at(3));
            course_map[course]->add(Bnum, course, points);
        }
        if ((str_vec.at(0) == "promote") && (str_vec.size() == 4)) {
            Bnum = str_vec.at(1);
            course = str_vec.at(2);
            points = stoi(str_vec.at(3));
            course_map[course]->promote(Bnum, points);
        }
        if ((str_vec.at(0) == "enroll") && (str_vec.size() == 2)) {
            course = str_vec.at(1);
            MaxHeap* heapObj = course_map[course];
            Node* student = heapObj->enroll();
            string studentBnum = student->getBnum();

            // loop through all MaxHeap in the map and take off all the priority points 
            // of the student that was enrolled from other class
            for (auto& pair : course_map) {
                if (pair.first != course) {
                    pair.second->promote(studentBnum, 0);
                }
            }
        }

        Bnum.clear();
        course.clear();
        points = 0;
        str_vec.clear();
        cout << endl;
        cout << "Enter Command: ";
        getline(cin, userLineInput);
        stringstream ss(userLineInput);
        while (ss >> userLineInput) {
            str_vec.push_back(userLineInput);
        }

        if (str_vec.at(0) == "quit") {
            exit(0);
    }

    }
}