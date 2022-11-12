//
// Created by lzw on 2022/11/12.
//

#include "leetcode790.h"

#include "vector"
//https://leetcode.cn/problems/domino-and-tromino-tiling/solution/java-by-tizzi-ywmu/
int leetcode790::numTilings(int n) {
    int mod=int(1e9+7);
    std::vector<int> dp(n+1);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(2*dp[i-1]%mod+dp[i-3]%mod)%mod;
    }
    return dp[n];
}