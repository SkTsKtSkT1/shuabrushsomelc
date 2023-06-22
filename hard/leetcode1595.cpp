//
// Created by 25467 on 2023/6/20.
//

#include "leetcode1595.h"
#include "iostream"
#include "functional"
//https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/solution/jiao-ni-yi-bu-bu-si-kao-dong-tai-gui-hua-djxq/
int leetcode1595::connectTwoGroups(std::vector<std::vector<int>> &cost) {
    int n = cost.size(), m = cost[0].size();
    std::vector<int> min_cost(m, INT_MAX);
    for (int j = 0; j < m; j++)
        for (auto &c: cost)
            min_cost[j] = std::min(min_cost[j], c[j]);

    std::vector<std::vector<int>> memo(n, std::vector<int>(1 << m, INT_MAX));
    std::function<int(int, int)> dfs = [&](int i, int j) -> int {
        if (i < 0) {
            int res = 0;
            for (int k = 0; k < m; k++)
                if (j >> k & 1) // 第二组的点 k 未连接
                    res += min_cost[k]; // 去第一组找个成本最小的点连接
            return res;
        }
        int &res = memo[i][j]; // 注意这里是引用
        if (res != INT_MAX) return res; // 之前算过了
        for (int k = 0; k < m; k++) // 第一组的点 i 与第二组的点 k
            res = std::min(res, dfs(i - 1, j & ~(1 << k)) + cost[i][k]);
        return res;
    };
    return dfs(n - 1, (1 << m) - 1);
}
