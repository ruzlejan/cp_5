#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>
#include "pr_check.h"

using namespace std;

pr_check::pr_check() : max_depth{0}, course_map{}{
    

}

bool pr_check::dfs(unordered_map<string,vector<string>> &course_map, unordered_set<string> &visited, unordered_set<string> &recursion_stack, const string &course, int depth, int &max_depth) {
    visited.insert(course);
    recursion_stack.insert(course);

    if (depth > max_depth) {
        max_depth = depth;
    }

    for (const auto& prereq : course_map[course]) {
        if (!visited.count(prereq)) {
            if (dfs(course_map, visited, recursion_stack, prereq, depth + 1, max_depth)) {
                return true;
            }
        } else if (recursion_stack.count(prereq)) {
            // If a cycle is detected, return true
            return true;
        }
    }

    recursion_stack.erase(course);

    return false;
}

bool pr_check::has_cycle(unordered_map<string,vector<string>> &course_map) {
    unordered_set<string> visited;
    unordered_set<string> recursion_stack;
      
    for (const auto& course : course_map) {
        if (!visited.count(course.first)) {
            if (dfs(course_map, visited, recursion_stack, course.first, 0, max_depth)) {
                return true;
            }
        }
    }

    return false;
}

int pr_check::getMaxDepth(){
    return this->max_depth;
}


unordered_map<string,vector<string>>& pr_check::getMap(){
    return this->course_map;
}


string pr_check::pr_reader(string fileName){


    //open the file
    ifstream file(fileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open "  << endl;
        return NULL;
    }

   

   //unordered_map<string,vector<string>> course_map;
    string line;
    // Read the file contents and store it into an unordered map
    while(getline(file,line)){
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
                course_map[course] = vector<std::string>();
                // Add the new prerequisite to the empty vector
                course_map[course].push_back(prereq);
            }
            //add courses that has no prerequisites with an empty vector
            if(prereq_it == course_map.end()){
                course_map[prereq] = vector<std::string>();
            }
        }
    }


     for (const auto& [course, prereq_list] : course_map) {
        cout << course << ": ";
        for (const auto& prereq : prereq_list) {
            cout << prereq << " ";
        }
        cout << endl;
    }

   


    if(!has_cycle(course_map)){
        cout << "Passed: No Cycle" << endl;
        if(getMaxDepth() < 6){
            cout << "Passed: Can be done in 6 semesters" << endl;
            return "Viable";
        }else{
            cout << "Failed: Too many courses" << endl;
            return "Not Viable";
        }
    }else{
        cout << "Failed: Has Cycle" << endl;
        return "Not Viable";
    }

    



}