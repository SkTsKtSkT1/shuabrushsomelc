//
// Created by 25467 on 2023/7/13.
//

#include "leetcode931.h"
#include "algorithm"

int leetcode931::minFallingPathSum(std::vector<std::vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        dp[0][i] = matrix[0][i];
    }
    for(int i = 1; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(j == 0) {
                dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j + 1]}) + matrix[i][j];
            }else if(j == m - 1){
                dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - 1]}) + matrix[i][j];
            }else{
                dp[i][j] = std::min({dp[i - 1][j], dp[i - 1][j - 1], dp[i - 1][j + 1]}) + matrix[i][j];
            }
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < n; ++i){
        res =std::min(res, dp[m - 1][i]);
    }
    return res;
}
