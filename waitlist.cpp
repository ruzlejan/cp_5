#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include "Node.h"
#include "MaxHeap.h"
#include "pr_check.h"
#include "sch_check.h"

using namespace std;


 unordered_map<string, MaxHeap*> courses_map;

 void newlist(string courseName) {
    courses_map[courseName] = new MaxHeap(courseName);
}

int main(int argc, char* argv[]) {
  
    //1. extract argv[2] "Prerequisites.txt"
    //2. check each students' prerequisite viabilities
    //3. if viable, store it to unordered_map<string Bnum, string fileName>
    
    unordered_map<string,string> viablePrereqs;
    
    pr_check* pr_checkobj = new pr_check();
    ifstream file(argv[2]);
    if (!file.is_open()) {
        std::cerr << "Failed to open "  << endl;
        return 0;
    }

    string line;
        // Read the file contents and store it into an unordered map
        while(getline(file,line)){
        stringstream ss(line);
        string Bnum;
        ss >> Bnum;

        string fileName;
        string result = pr_checkobj->pr_reader(fileName);
        if(result == "Viable"){
            //store it in an unorderedmap<string,string>
            viablePrereqs[Bnum] = fileName;
        }
        pr_checkobj->getMap().clear(); 
    }
    file.close();
//print viable prereqs
cout << "Viable Prerequisites:" <<endl ;
for (const auto& entry : viablePrereqs) { 
        cout << "Bnum " << entry.first << " is viable with prereqs in file " << entry.second << endl;
}


//1. extract argv[3] "Schedules.txt"
//2. check check each students' schedule viabilities by checking if a student's 
//prereq is viable from the map viablePrereqs, and if exists, extract fileName from viablePrereqs map and check for
//schedule viability
//3. if students' schedule are viable, store it in unordered_map<string bNum,string result> that will be used 
//in waitlist to verify

unordered_map<string,string> viableSchedules;
sch_check* sch_checkobj = new sch_check();

    ifstream file2(argv[3]);
    if (!file2.is_open()) {
        std::cerr << "Failed to open "  << endl;
        return 0;
    }

string inputLine;
 // Read the file contents and store it into an unordered map
while (getline(file2, inputLine)) {
    stringstream schedss(inputLine);
    string schBnum;
    schedss >> schBnum;
    string schFileName;
    schedss >> schFileName;

    auto it = viablePrereqs.find(schBnum);
    if (it != viablePrereqs.end()) {
        string fileName = it->second;
        string result = sch_checkobj->sch_reader(fileName, schFileName);
        if (result == "Viable") {
            // Store the viable schedules in an unordered_map<string, string>
            viableSchedules[schBnum] = "Viable";
        }
    }
}
file2.close();

//printing viable schedules
cout << "Viable Schedules: " << endl;
for (const auto& entry : viableSchedules) { 
        cout << "Bnum " << entry.first << " is viable schedule in the file  " << entry.second << endl;
}

//waitlist
   vector<string> str_vec;
    string userLineInput;

    string Bnum;
    string course;
    int points;

    // Open the file for reading
    ifstream inputFile(argv[4]);

    // Check if file was opened successfully
    if (!inputFile.is_open()) {
        cout << "Error: unable to open file." << endl;
        return 1;
    }

    // Read lines from the file and process each line
    while (getline(inputFile, userLineInput)) {
        stringstream ss(userLineInput);
        while (ss >> userLineInput) {
            str_vec.push_back(userLineInput);
        }

        if (str_vec.at(0) == "newlist") {
            course = str_vec.at(1);
            newlist(course);
            cout << "Course " << str_vec.at(1) << " created." << endl;
        }
        else if (str_vec.at(0) == "add") {
            Bnum = str_vec.at(1);
            course = str_vec.at(2);
            points = stoi(str_vec.at(3));

            // Check if Bnum exists in viableSchedules
            if (viableSchedules.find(Bnum) != viableSchedules.end()) {
                courses_map[course]->add(Bnum, course, points);
            }
            else {
                cout << "Error: Student " << Bnum << " does not exist in viableSchedules." << endl;
            }
        }
        else if (str_vec.at(0) == "promote") {
            Bnum = str_vec.at(1);
            course = str_vec.at(2);
            points = stoi(str_vec.at(3));

            // Check if Bnum exists in viableSchedules
            if (viableSchedules.find(Bnum) != viableSchedules.end()) {
                courses_map[course]->promote(Bnum, points);
            }
            else {
                cout << "Error: Student " << Bnum << " does not exist in viableSchedules." << endl;
            }
        }
        else if (str_vec.at(0) == "enroll") {
            course = str_vec.at(1);
            MaxHeap* heapObj = courses_map[course];
            Node* student = heapObj->enroll();
            string studentBnum = student->getBnum();
            cout << "Enrolling student " << studentBnum << " in course " << course << endl;

            // loop through all MaxHeap in the map and take off all the priority points 
            // of the student that was enrolled from other class
            for (auto& pair : courses_map) {
                if (pair.first != course) {
                    pair.second->promote(studentBnum, 0);
                }
            }
        }
        else {
            cout << "Error: invalid command." << endl;
        }

        Bnum.clear();
        course.clear();
        points = 0;
        str_vec.clear();
    }

    inputFile.close();
    
    return 0;
}

