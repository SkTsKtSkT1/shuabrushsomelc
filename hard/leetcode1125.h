//
// Created by skt on 2023/4/8.
//

#ifndef ALGORITHM_LEETCODE1125_H
#define ALGORITHM_LEETCODE1125_H
#include "vector"
#include "string"
#include "ostream"
#include "iostream"
using std::string;
using std::vector;

class leetcode1125 {
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people);
    std::ostream& operator<<(const vector<int> v);
};

#endif //ALGORITHM_LEETCODE1125_H
