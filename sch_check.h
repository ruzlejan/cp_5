#ifndef SCH_CHECK_H
#define SCH_CHECK_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class sch_check{
    private:
    
    unordered_map<string,vector<string>> schedule_map;

    public:
    bool sameCourse(unordered_map<string,vector<string>> &schedule_map);
    bool isBefore(string string1,string string2);
    bool viability( unordered_map<string,vector<string>> &course_map, unordered_map<string,vector<string>> &schedule_map);
    bool isTooMany(const unordered_map<string,vector<string>>& schedule_map);
    string sch_reader(string prereqFile,string schFile);
   
    
};


#endif