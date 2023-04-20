//
// Created by 25467 on 2023/4/19.
//

#include "leetcode283.h"

void leetcode283::moveZeroes(vector<int> &nums) {
    int left=0,right=0;
    int len=nums.size();
    while(right<len){
        if(nums[right]){
            std::swap(nums[left],nums[right]);
            left++;
        }
        right++;
    }
    return;
}
