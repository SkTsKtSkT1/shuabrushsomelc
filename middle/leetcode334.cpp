//
// Created by 25467 on 2023/4/19.
//

#include "leetcode334.h"
#include "iostream"
//a 始终记录最小元素，b 为某个子序列里第二大的数。
//
//接下来不断更新 a，同时保持 b 尽可能的小。
//
//如果下一个元素比 b 大，说明找到了三元组。
bool leetcode334::increasingTriplet(vector<int> &nums) {
    int a = INT_MAX, b = INT_MAX;
    int n = nums.size();
    for(int& num:nums){
        if(num <= a){
            a = num;
        }else if(num <= b){// now a<num;
            b = num; // then b is smaller
        }else{ // now a<num && b is smallest and num>b
            return true;
        }
    }
    return false;
}
