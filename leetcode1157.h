//
// Created by 25467 on 2023/4/16.
//

#ifndef ALGORITHM_LEETCODE1157_H
#define ALGORITHM_LEETCODE1157_H

#include <random>
#include "vector"
#include "unordered_map"
using std::vector;

class MajorityChecker {
public:
    std::unordered_map<int,vector<int>> m;
    MajorityChecker(vector<int>& arr);

    int query(int left, int right, int threshold);
private:
    static constexpr int k=30;
    const vector<int>& arr;
    //don't know
    std::mt19937 gen{std::random_device{}()};

};


#endif //ALGORITHM_LEETCODE1157_H
