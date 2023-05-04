#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <vector>
#include <queue>
#include "pr_check.cpp"
#include "sch_check.h"

using namespace std;

bool sch_check::sameCourse(unordered_map<string,vector<string>> &schedule_map){
for(const auto& values:schedule_map){
    const auto& numValues = values.second;
    if(numValues.size() > 1){
        return true;
    }
}
return false;
}



bool sch_check::isBefore(string string1,string string2){
    string semester1 = string1.substr(0,4);
    string semester2 = string2.substr(0,4);
    int sem1 = stoi(semester1);
    int sem2 = stoi(semester2);
    
   if (sem1 == sem2) {
        if (string1.length() > 4) {
            string semChecker1 = string1.substr(4, string1.length() - 4);
            string semChecker2 = string2.substr(4,string2.length()-4);
            if (semChecker1 == "Spring" && semChecker2 == "Summer") {
          return true;
            } else if(semChecker1 == "Spring" && semChecker2 == "Fall"){
                return true;
            }else if(semChecker1 == "Summer" && semChecker2 == "Fall"){
                return true;
            }else {
                return false;
            }
        } else {
            return false;
        }
    }else if(sem1 < sem2){
        return true;
    }
    else{
        return false;
    }
}





bool sch_check::viability(unordered_map<string,vector<string>> &course_map,unordered_map<string,vector<string>> &schedule_map){
    for(const auto &course:schedule_map){
        string semCourse = course.second[0];
        for(const auto &prereq:course_map[course.first]){
            auto prereq_itr = schedule_map.find(prereq);
            if(prereq_itr == schedule_map.end()) {
                // element not found in schedule_map means theres no prereq
                continue;
            }
            string semPrereq = prereq_itr->second[0];
            if(!isBefore(semPrereq,semCourse)){
                return false;
            }
        }
    }   
    return true;
}

bool sch_check::isTooMany(const unordered_map<string, vector<string>>& schedule_map) {
//swapping key-value of existing unordered_map into value-key relation and store it in a new unordered map
unordered_map<string,vector<string>> newMap;
    for (const auto& kv : schedule_map) {
        string key = kv.first;
        string value = kv.second[0];
        newMap[value].push_back(key);
    }
    //print new map
    for (const auto& kv : newMap) {
        cout << kv.first << ": ";
        for (const auto& value : kv.second) {
            cout << value << " ";
        }
        cout << endl;
    }
//check if courses taken in a semester is more then 3
for(const auto& values:newMap){
    const auto& numValues = values.second;
    if(numValues.size() > 3){
        return true;
    }
}
    
    return false;
}




 string sch_check:: sch_reader(){


    // //open the file
    // ifstream infile1(argv[1]);
    // if (!infile1.is_open()) {
    //     cerr << "Failed to open " << argv[1] << endl;
    //     return 1;
    // }
    // unordered_map<string,vector<string>> course_map;
    // string line;
    // // Read the file contents and store it into an unordered map
    // while(getline(infile1,line)){
    //     stringstream ss(line);
    //     string course;
    //     ss >> course;

       
    //     string prereq;
    //     while (ss >> prereq) {
    //         // Check if the course already exists in the map
    //         auto iterator = course_map.find(course);
    //         auto prereq_it = course_map.find(prereq);
    //         if (iterator != course_map.end()) {
    //             // Add the new prerequisite to the existing vector
    //             iterator->second.push_back(prereq);
    //         }else {
    //             // Add a new element to the map with an empty vector
    //             course_map[course] = vector<string>();
    //             // Add the new prerequisite to the empty vector
    //             course_map[course].push_back(prereq);
    //         }
    //         //add courses that has no prerequisites with an empty vector
    //         if(prereq_it == course_map.end()){
    //             course_map[prereq] = vector<string>();
    //         }
    //     }
    // }

    //extracting the schedfile.txt

       //open the file
       pr_check* prschedule = new pr_check();
       prschedule->pr_reader();
    ifstream infile2("schedfile.txt");
    if (!infile2.is_open()) {
        cerr << "Failed to open " <<  endl;
        return NULL;
    }   

    unordered_map<string,vector<string>> schedule_map;
    string schedline;
    while(getline(infile2,schedline)){
        stringstream schedss(schedline);
        string sched_course;
        string semester;
  if (schedss >> sched_course >> semester) {
            schedule_map[sched_course].push_back(semester);
        }
    }

        //printing schedule map
        for (const auto& kv : schedule_map) {
        cout << kv.first << ": ";
        for (const auto& value : kv.second) {
            cout << value << " ";
        }
        cout << endl;
    }

    if( prschedule->pr_reader() == "Viable"){
        if(!sameCourse(schedule_map)){
            cout << "Bullet1: passed" << endl;
            if(viability(course_map,schedule_map)){
            cout<< "Bullet 2: Passed" << endl;
                 if(!isTooMany(schedule_map)){
            cout << "Bullet 3: Passed" << endl;
                return "Viable";
                }else{
                 cout << "Bullet 3: Failed" << endl;
                return "Not Viable";
            }
             }else{
            cout << "Bullet 2: Failed" << endl;
            return "Not Viable";
        }
        }else{
            cout << "Bullet 1: failed" << endl;
            return "Not Viable";
        }
    }else{
        return "Not Viable";
    }






        // if(viability(course_map,schedule_map)){
        //     cout<< "Bullet 2: Passed" << endl;
        // }else{
        //     cout << "Bullet 2: Not passed" << endl;
        // }
        // if(!sameCourse(schedule_map)){
        //     cout << "There are no courses are taken more than once" << endl;
        //     if(!isTooMany(schedule_map)){
        //     cout << "Student proposed at most 3 courses in a semester" << endl;
        //         return 0;
        //     }else{
        //     cout << "Error: More than 3 courses in a semester" << endl;
        //     return 1;
        //     }
        // }else{
        //     cout << "courses have been taken more than once" << endl;
        //     return 1;
        // }
        // return 0;

}