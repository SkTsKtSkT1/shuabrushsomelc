//
// Created by lzw on 2022/8/23.
//

#ifndef ALGORITHM_LEETCODE40_H
#define ALGORITHM_LEETCODE40_H

#include "iostream"
#include "vector"
#include "algorithm"

class leetcode40 {
public:
    std::vector<std::vector<int>> result;

    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target);

    void dfs(std::vector<int>& nums,std::vector<int> path,std::vector<bool> used,int start,int sum,int target);
};


#endif //ALGORITHM_LEETCODE40_H
