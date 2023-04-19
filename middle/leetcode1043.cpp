//
// Created by 25467 on 2023/4/19.
//

#include "leetcode1043.h"
//对于数组求 最大  最小问题 一般为 动态规划问题
//
//建立一维数组 dp[i] 表示：从 0 到 位置 i 子数组的最大和
//转移方程：
//dp[i]=dp[j]+(i-j)*max(arr[i],...,arr[j]);
//use domain_max to get the max(arr[i],...,arr[j])
//where j>=0; dp[0]=0;
int leetcode1043::maxSumAfterPartitioning(vector<int> &arr, int k) {
    vector<int> dp(arr.size());
    for(int i=0;i<arr.size();i++){
        int domain_max=-1;
        for(int j=i-1;j>=std::max(0,i-k);j--){ //倒着找最大的
            domain_max=std::max(domain_max,arr[j]);
            dp[i]=std::max(dp[i],dp[j]+(i-j)*domain_max);
        }
    }
    return dp[arr.size()];
}
