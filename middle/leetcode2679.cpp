//
// Created by 25467 on 2023/7/4.
//

#include "leetcode2679.h"
#include "algorithm"

int leetcode2679::matrixSum(std::vector<std::vector<int>> &nums) {
    //对每一行进行排序，然后求出每一列最大值之和
    for(int i = 0; i < nums.size(); ++i){
        std::sort(nums[i].begin(), nums[i].end(), [&](int pre, int nxt) -> bool{
           return pre > nxt;
        });
    }
    int res = 0;
    for(int i = 0; i < nums[0].size(); ++i){
        int max_element = 0;
        for(int j = 0; j < nums.size(); ++j){
            max_element = std::max(max_element, nums[j][i]);
        }
        res += max_element;
    }
    return res;
}
