//
// Created by 25467 on 2023/4/21.
//

#include "leetcode1004.h"

int leetcode1004::longestOnes(vector<int> &nums, int k) {
    int max=0;
    int l=0;
    //to find a max 1 with 0 less than k;
    for(int r=0;r<nums.size();r++){
        if(nums[r]==0) k--;
        while(l<=r && k<0){
            if(nums[l++]==0) k++;
        }
        max=std::max(r-l+1,max);
    }
    return max;
}
