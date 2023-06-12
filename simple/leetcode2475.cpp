//
// Created by skt on 2023/6/13.
//

#include "leetcode2475.h"
#include "algorithm"
#include "map"
int leetcode2475::unequalTriplets(std::vector<int> &nums) {
    std::map<int, int> m;
    int res = 0, start = 0, n = nums.size();
    for(int& num : nums){
        m[num]++;
    }
    int tmp;
    for(auto& el : m){
        tmp = el.second;
        n -= tmp;
        res += start * tmp * n;
        start += tmp;
    }

    return res;
}
