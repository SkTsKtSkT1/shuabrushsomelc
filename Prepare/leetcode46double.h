//
// Created by 25467 on 2023/4/12.
//

#ifndef ALGORITHM_LEETCODE46DOUBLE_H
#define ALGORITHM_LEETCODE46DOUBLE_H
#include "vector"
#include "ostream"
#include "iostream"
using std::vector;

class leetcode46double{
private:
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums);
    void dfs(vector<int>&nums, vector<int>& used, vector<int>& path);
    std::ostream &operator<<(const vector<vector<int>> &v);
};


#endif //ALGORITHM_LEETCODE46DOUBLE_H
