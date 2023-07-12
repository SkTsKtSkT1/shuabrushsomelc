//
// Created by 25467 on 2023/7/11.
//

#include "leetcode1911.h"
#include "cstring"

long long leetcode1911::maxAlternatingSum(std::vector<int> &nums) {
    int n = nums.size();
    long long f[2];
    memset(f, 0, sizeof(f));
    for ( int i = 0; i < n; ++i ) {
        f[1] = std::max(f[0] - nums[i], f[1]);
        f[0] = std::max(f[1] + nums[i], f[0]);
    }
    return std::max(f[0], f[1]);
}
