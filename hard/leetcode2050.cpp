//
// Created by 25467 on 2023/7/28.
//

#include "leetcode2050.h"

int leetcode2050::minimumTime(int n, std::vector<std::vector<int>> &relations, std::vector<int> &time) {
        this->time = time;
        pre.resize(n);
        dp.resize(n);
        for (std::vector<int> &relation: relations) {
            pre[relation[1] - 1].push_back(relation[0] - 1);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = std::max(ans, dfs(i));
        }
        return ans;

}

int leetcode2050::dfs(int n) {
    if (dp[n]) {
        return dp[n];
    }
    for (int thisPre : pre[n]) {
        // printf("n = %d, thisPre = %d, max(%d", n, thisPre, dp[n]);  //******
        dp[n] = std::max(dp[n], dfs(thisPre));
        // printf(", %d) = %d\n", dfs(thisPre), dp[n]);  //*********
    }
    return (dp[n] += time[n]);
}
