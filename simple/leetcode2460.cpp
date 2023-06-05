//
// Created by 25467 on 2023/6/5.
//

#include "leetcode2460.h"

std::vector<int> leetcode2460::applyOperations(std::vector<int> &nums) {
    for(int i = 0;i < nums.size() - 1; i++){
        if(nums[i] == nums[i + 1]){
            nums[i] *= 2;
            nums[i + 1] = 0;
        }else continue;
    }

    int i = 0, j = 0;
    while(j < nums.size()){
        if(nums[j] == 0){
            j++;
        }else{
            nums[i++] = nums[j++];
        }
    }
    while(i < nums.size()){
        nums[i++] = 0;
    }
    return nums;
}
