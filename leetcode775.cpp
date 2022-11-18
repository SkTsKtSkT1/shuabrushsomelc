//
// Created by lzw on 2022/11/16.
//

#include "leetcode775.h"
#include "cmath"
bool leetcode775::isIdealPermutation(vector<int> &nums) {
//要求一个局部倒置就是一个全局倒置，也就是倒置的长度应该为2； 思路对了但是超时了。。
//    for(int i=0;i<nums.size()-1;i++){
//        for(int j=i+2;j<nums.size();j++){
//            if(nums[j]<nums[i]) return false;
//        }
//    }
//    return true;
    //如果数列进行排序后，数字是和下标一一对应，如果这个数和下标差距大于1，则return false;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=i && abs(nums[i]-i)>1){
            return false;
        }
    }
    return true;
}