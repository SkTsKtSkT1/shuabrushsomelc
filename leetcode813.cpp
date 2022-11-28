//
// Created by lzw on 2022/11/28.
//

#include "leetcode813.h"
#include "algorithm"

double leetcode813::largestSumOfAverages(vector<int> &nums, int k) {
    //动态规划
    //令 dp[i][k] 表示：将 nums 中的前 i 个数分成 k 个子数组的最大平均值和。那么：

    //j = 1 时，dp[i][1] = (nums[0] + ... + nums[i - 1]) / i;
    //j > 1 时，dp[i][j] = max(dp[i][j],dp[m][j - 1] + avg[m][i])。j 在 [0, i - 1] 之间。其中 avg[m][i] 为区间 [m, i - 1] 的平均值。avg[m][i] = (nums[m] + ... + nums[i - 1]) / (i - m)。
    //为了快速计算 avg[m][i]， 我们可以预处理 nums 的前缀和。
    //要求分i个数字为j组时，最大的和是dp[m][j-1]+avg(m,i) 已经分了m个，j-1组
    int n=nums.size();
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+nums[i-1];
    }

    vector<vector<double>> dp(n+1,vector<double>(k+1,0));
    for(int i=1;i<=n;i++){
        dp[i][1]=sum[i]*1.0/i;
    }
    //enum how many nums
    for (int i = 1; i <= n; i++) {
        //enum how many 组
        for (int j = 2; j <= k; j++) {
            //已经分了m组
            for (int m = 1; m < i; m++) {
                // 求 [j, i - 1] 中的平均值
                double avg = (sum[i] - sum[m]) * 1.0 / (i - m);
                dp[i][j] = std::max(dp[i][j], dp[m][j - 1] + avg);
            }
        }
    }

    return dp[n][k];
}