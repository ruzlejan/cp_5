#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <unordered_set>
#include <vector>
#include "pr_check.cpp"

using namespace std;



bool isBefore(string string1,string string2){
    string semester1 = string1.substr(0,4);
    string semester2 = string2.substr(0,4);
    int sem1 = stoi(semester1);
    cout << sem1 << endl;
    int sem2 = stoi(semester2);
    cout << sem2 << endl;
   if (sem1 == sem2) {
        if (string1.length() > 4) {
            string semChecker = string1.substr(4, string1.length() - 4);
            cout << semChecker << endl;
            if (semChecker == "Spring") {
          return true;
            } else {
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


bool viability(unordered_map<string,vector<string>> &course_map,unordered_map<string,string> &schedule_map){
 for(const auto &course:schedule_map){
    string semCourse = course.second;
    for(const auto &prereq:course_map[course.first]){
        auto prereq_itr = schedule_map.find(prereq);
        string semPrereq = prereq_itr->second;
        if(!isBefore(semPrereq,semCourse)){
            return false;
        }
    }
 }   
 return true;
}





int main(int argc, char* argv[]){


    //open the file
    ifstream infile1(argv[1]);
    if (!infile1.is_open()) {
        cerr << "Failed to open " << argv[1] << endl;
        return 1;
    }
    unordered_map<string,vector<string>> course_map;
    string line;
    // Read the file contents and store it into an unordered map
    while(getline(infile1,line)){
        stringstream ss(line);
        string course;
        ss >> course;

       
        string prereq;
        while (ss >> prereq) {
            // Check if the course already exists in the map
            auto iterator = course_map.find(course);
            auto prereq_it = course_map.find(prereq);
            if (iterator != course_map.end()) {
                // Add the new prerequisite to the existing vector
                iterator->second.push_back(prereq);
            }else {
                // Add a new element to the map with an empty vector
                course_map[course] = vector<string>();
                // Add the new prerequisite to the empty vector
                course_map[course].push_back(prereq);
            }
            //add courses that has no prerequisites with an empty vector
            if(prereq_it == course_map.end()){
                course_map[prereq] = vector<string>();
            }
        }
    }

    //extracting the schedfile.txt

       //open the file
    ifstream infile2(argv[2]);
    if (!infile2.is_open()) {
        cerr << "Failed to open " << argv[2] << endl;
        return 1;
    }   

    unordered_map<string,string> schedule_map;
    string schedline;
    while(getline(infile2,schedline)){
        stringstream schedss(schedline);
        string sched_course;
        schedss >> sched_course;
        string semester;
        schedss >> semester;
        schedule_map.insert({sched_course,semester});
    }

    if(!has_cycle(course_map) && max_depth < 6 ){
        cout << "Graph does not contain a cycle and can be done with 6 semester. Therefore, its viable" << endl;
        cout << "max_depth: "<<max_depth<<endl;
        //call viability function
        if(viability(course_map,schedule_map)){
            cout << "Proposed schedule is viable" << endl;
            return 0;
        }else{
            cout << "Proposed schedule is not viable" << endl;
            return 1;
        }
        //return 0;
    }else{
        cout << "Graph contains a cycle or cannot be done with 6 semester. Therefore, it not viable"  << endl;
        cout << "max_depth: "<<max_depth<<endl;
        //return 1;
    }


}