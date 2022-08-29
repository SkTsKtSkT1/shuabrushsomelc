//
// Created by lzw on 2022/8/29.
//

#include "leetcode1470.h"


std::vector<int> leetcode1470::shuffle(std::vector<int>& nums, int n) {
    int len=nums.size();
    std::vector<int> result;
    for(int i=0;i<len/2;i++){
        result.push_back(nums[i]);
        result.push_back(nums[i+len/2]);
    }
    return  result;
}