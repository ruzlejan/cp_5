#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;
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

       
        std::string prereq;
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




    return 0;
}