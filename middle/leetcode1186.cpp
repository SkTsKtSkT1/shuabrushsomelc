//
// Created by 25467 on 2023/6/27.
//

#include <cstring>
#include "leetcode1186.h"
#include "algorithm"
//https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/solutions/2314975/shan-chu-yi-ci-de-dao-zi-shu-zu-de-zui-d-o1o9/
//dp[i][j] -> 前i个进行j次删除的结果
// dp[0][0] = arr[0], dp[0][1] = 0
//dp[i][0] = max(dp[i-1][0], 0) + arr[i]; ->如果前面的小于0，不要了 arr[i]可能就是最大和
//dp[i][1] = max(dp[i-1][1] + arr[i], arr[i-1][0])
//然后对于找出整个数组的最大值
int leetcode1186::maximumSum(std::vector<int> &arr) {
    int n = arr.size();
    int dp[n][2];
    int res = arr[0];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = arr[0];
    dp[0][1] = 0;
    for(int i = 1; i < n; i++){
        dp[i][0] = std::max(dp[i - 1][0], 0) + arr[i];
        dp[i][1] = std::max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        res = std::max({res, dp[i][0], dp[i][1]});
    }
    return res;
}
