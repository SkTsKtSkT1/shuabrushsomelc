//
// Created by 25467 on 2023/9/17.
//

#include "leetcode213.h"
#include <cstring>

int leetcode213::rob(std::vector<int> &nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    if(n == 2){
        return std::max(nums[0], nums[1]);
    }
    return std::max(rob1(nums, 0, n - 2), rob1(nums, 1, n - 1));
}

int leetcode213::rob1(std::vector<int> &nums, int begin, int end) {
    int n = end - begin + 1; //n个house

    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    //dp[i] 前i个房子最大的值
    dp[1] = nums[begin];
    for(int i = 2; i < n + 2; ++i){
        dp[i] = std::max(nums[begin + i - 1] + dp[i - 2], dp[i - 1]);
    }
    return dp[n];
}
