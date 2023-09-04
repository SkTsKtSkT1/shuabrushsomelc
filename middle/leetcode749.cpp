//
// Created by skt on 2023/8/8.
//

#include "leetcode749.h"
#include <cstring>
#include "cmath"
//use dp, dp[i] 表示以nums[i]结尾的子数组的最大和的绝对值
//dp[i + 1] = std::max(dp[i] + nums[i + 1], nums[i + 1])
//dp[0] = 0
int leetcode749::maxAbsoluteSum(std::vector<int> &nums) {
    size_t n = nums.size();
    int dp[n];
    memset(dp, 0, sizeof(dp));
    dp[0] = nums[0];
    for(int i = 1; i < n; ++i){
        dp[i] = std::max(dp[i - 1] + nums[i], nums[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        ans = std::max(ans, std::abs(dp[i]));
    }
    for(int i = 1; i <n; ++i){
        dp[i] = std::min(dp[i - 1] + nums[i], nums[i]);
    }
    for(int i = 0; i < n; ++i){
        ans = std::max(ans, std::abs(dp[i]));
    }
    return ans;


    return 0;
}
