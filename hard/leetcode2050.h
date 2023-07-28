//
// Created by 25467 on 2023/7/28.
//

#ifndef ALGORITHM_LEETCODE2050_H
#define ALGORITHM_LEETCODE2050_H

#include "vector"
class leetcode2050 {
private:
    std::vector<std::vector<int>> pre;
    std::vector<int> dp;
    std::vector<int> time;

    int dfs(int n);
public:
    int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time);
};


#endif //ALGORITHM_LEETCODE2050_H
