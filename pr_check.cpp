#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <fstream>

using namespace std;

 int max_depth = 0;

bool dfs(unordered_map<string,vector<string>> &course_map, unordered_set<string> &visited, const string &course,int depth,int &max_depth){
    visited.insert(course);

    if(depth > max_depth){
        max_depth = depth;
    }

    for(const auto& prereq: course_map[course]){
        if(!visited.count(prereq)){
            if(dfs(course_map,visited,prereq,depth + 1, max_depth)){
                return true;
            }
        }
    }

    
    return false;
}

bool has_cycle(unordered_map<string,vector<string>> &course_map){
    unordered_set<string> visited;
      
    for(const auto& course: course_map){
        if(!visited.count(course.first)){
              if (dfs(course_map, visited,course.first,0,max_depth)) {
                return true;
        }
    }
}
    return false;
}


/*
int main(int argc, char* argv[]){

     if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <prereqfile>" << endl;
        return 1;
    }

    //open the file
    ifstream infile(argv[1]);
    if (!infile.is_open()) {
        std::cerr << "Failed to open " << argv[1] << std::endl;
        return 1;
    }
    unordered_map<string,vector<string>> course_map;
    string line;
    // Read the file contents and store it into an unordered map
    while(getline(infile,line)){
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

   

    if(!has_cycle(course_map) && max_depth < 6 ){
        cout << "Graph does not contain a cycle and can be done with 6 semester. Therefore, its viable" << endl;
        cout << "max_depth: "<<max_depth<<endl;
    }else{
        cout << "Graph contains a cycle or cannot be done with 6 semester. Therefore, it not viable"  << endl;
        cout << "max_depth: "<<max_depth<<endl;
    }

    
     for (const auto& [course, prereq_list] : course_map) {
        cout << course << ": ";
        for (const auto& prereq : prereq_list) {
            cout << prereq << " ";
        }
        cout << endl;
    }




    return 0;
}*/