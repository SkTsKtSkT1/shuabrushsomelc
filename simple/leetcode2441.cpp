//
// Created by 25467 on 2023/5/13.
//

#include "leetcode2441.h"
#include "unordered_set"
int leetcode2441::findMaxK(vector<int> &nums) {
    std::unordered_set<int> us;
    int max = 0;
    for(int& n:nums){
        if(us.count(-n)){
            max = std::max(std::abs(n),max);
        }else{
            us.insert(n);
        }
    }
    return max == 0? -1:max;
}
