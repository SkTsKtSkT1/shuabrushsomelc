//
// Created by lzw on 2022/8/25.
//

#include "leetcode665.h"


bool leetcode665::checkPossibility(std::vector<int> &nums) {
    int len=nums.size();
    int counts=0;
    for(int i=1;i<len;i++){
        if(nums[i]<nums[i-1]){
            if(i==1 || nums[i-2]<=nums[i]){
                nums[i-1]=nums[i];  //如果在开头是大的数字 而且第二个小于第三个 那么把第一个变小就有可能，此时已经修改了一次。
            }else{
                nums[i]=nums[i-1];
            }
            counts++;
        }
    }

    return counts<=1;
}