//
// Created by 25467 on 2023/8/10.
//

#include <climits>
#include "leetcode1289.h"
#include "string.h"
int leetcode1289::minFallingPathSum(std::vector<std::vector<int>> &grid) {
    size_t n = grid.size();
    int dp[n][n];
    memset(&dp, 0, sizeof(dp));
    for(int i = 0; i < n; ++i){
        dp[0][i] = grid[0][i];
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n; ++j){
            int val = grid[i][j];
            dp[i][j] = INT_MAX;
            for(int p = 0; p < n; ++p){
                if(p != j){
                    dp[i][j] = std::min(dp[i][j], dp[i - 1][p] + val);
                }
            }
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; ++i){
        ans = std::min(dp[n - 1][i], ans);
    }
    return ans;
}
