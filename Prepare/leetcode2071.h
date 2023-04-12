//
// Created by 25467 on 2023/4/12.
//

#ifndef ALGORITHM_LEETCODE2071_H
#define ALGORITHM_LEETCODE2071_H

#include "vector"
using std::vector;

class leetcode2071 {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength);
    bool verify_satisfy(const vector<int> task, const vector<int> workers, int pills, int strength, int num);
};


#endif //ALGORITHM_LEETCODE2071_H
