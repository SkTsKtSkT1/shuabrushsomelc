//
// Created by skt on 2022/10/24.
//

#include "leetcode915.h"

int leetcode915::partitionDisjoint(vector<int> &nums) {
    int divIndex=0;
    //div means in nums[div] divide nums to left and right
    int maxNum=nums[0];
    int maxLeft=nums[0];
    for(int i=1;i<nums.size()-1;i++){//right left not null
        maxNum=std::max(maxNum,nums[i]);
        if(maxLeft>nums[i]){
            divIndex=i;
            maxLeft=maxNum;
        }
    }
    return divIndex+1;



}
