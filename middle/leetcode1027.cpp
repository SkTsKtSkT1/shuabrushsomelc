//
// Created by skt on 2023/4/22.
//

#include "leetcode1027.h"

//dp,dp[i][j]代表以nums[i]结尾，公差为j的最长子序列
//dp[i][j]=max(dp[k][j])+1,where nums[i]-nums[k]=j
//because 0 <= nums[i] <= 500, thus the max is -500-500;
int leetcode1027::longestArithSeqLength(vector<int> &nums) {
    int ans=0;
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(1001,1));
    for(int i=0;i<n;++i){
        for(int j=0;j<i;++j){
            int d =nums[i]-nums[j]+500; //d>0;
            dp[i][d]=std::max(dp[j][d]+1,dp[i][d]);
            ans=std::max(ans,dp[i][d]);
        }
    }

    return ans+1;
}
