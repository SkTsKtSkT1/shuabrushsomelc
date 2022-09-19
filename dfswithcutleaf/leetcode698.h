//
// Created by skt on 2022/9/20.
//

#ifndef ALGORITHM_LEETCODE698_H
#define ALGORITHM_LEETCODE698_H
#include "vector"
#include "algorithm"
#include "numeric"
using std::vector;

class leetcode698 {
private:
    bool dfs(vector<int> &nums,vector<int>& used,int k,int sum,int& target,int index);
public:
    bool canPartitionKSubsets(vector<int>& nums,int k);
};


#endif //ALGORITHM_LEETCODE698_H
