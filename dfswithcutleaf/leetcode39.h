//
// Created by lzw on 2022/8/23.
//

#ifndef ALGORITHM_LEETCODE39_H
#define ALGORITHM_LEETCODE39_H
#include "iostream"
#include "vector"
#include "algorithm"

class leetcode39 {
public:
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target);

    void dfs(std::vector<int>& nums,std::vector<int> path,int start,int sum,int target);
};


#endif //ALGORITHM_LEETCODE39_H
