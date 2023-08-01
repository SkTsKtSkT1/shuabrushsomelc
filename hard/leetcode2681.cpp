//
// Created by 25467 on 2023/8/1.
//

#include "leetcode2681.h"
#include "algorithm"
int leetcode2681::sumOfPower(std::vector<int> &nums) {
    const int MOD = 1e9 + 7;
    std::sort(nums.begin(), nums.end());
    int ans = 0, s = 0;
    for(long long x : nums){
        ans = (ans + x * x % MOD * (x + s)) % MOD;
        s = (s * 2 + x) % MOD;
    }
    return ans;
}
