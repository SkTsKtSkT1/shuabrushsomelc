//
// Created by skt on 2023/9/16.
//

#include "leetcode198.h"
//https://leetcode.cn/problems/house-robber/solutions/138131/dong-tai-gui-hua-jie-ti-si-bu-zou-xiang-jie-cjavap/?envType=daily-question&envId=2023-09-16
int leetcode198::rob(std::vector<int> &nums) {
    int n = nums.size();
    //dp[i] 表示前i间的最大收益[1, n)
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[1] = nums[0];
    for(int i = 2; i < n + 1; ++i){
        //偷前i - 1个 or 前i - 2个和 当前房子
        dp[i] = std::max(dp[i - 2] + nums[i - 1], dp[i - 1]);
    }
    return dp[n];
}
