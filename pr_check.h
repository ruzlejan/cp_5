#ifndef PR_CHECK_H
#define PR_CHECK_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class pr_check{
    private:
    int max_depth;
    unordered_map<string,vector<string>> course_map;

    public:
    pr_check();
    bool dfs(unordered_map<string,vector<string>> &course_map, unordered_set<string> &visited, const string &course,int depth,int &max_depth);
    bool has_cycle(unordered_map<string,vector<string>> &course_map);
    string pr_reader();

    int getMaxDepth();
};


#endif