//
// Created by 25467 on 2023/5/29.
//

#include "leetcode2455.h"

int leetcode2455::averageValue(std::vector<int> &nums) {
    int sum = 0, cnt = 0;
    for(int& num:nums){
        if(num%6 == 0){
            sum += num;
            cnt++;
        }
    }
    if(sum == 0) return 0;
    return sum/cnt;
}
