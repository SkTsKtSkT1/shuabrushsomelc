//
// Created by 25467 on 2023/9/22.
//

#include "leetcode2603.h"
#include "cmath"
int leetcode2603::collectTheCoins(std::vector<int> &coins, std::vector<std::vector<int>> &edges) {
    int n = coins.size();
    std::vector<std::vector<int>> g(n);
    std::vector<int> deg(n);
    for (auto &e: edges) {
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x); // 建图
        deg[x]++;
        deg[y]++; // 统计每个节点的度数（邻居个数）
    }

    int left_edges = n - 1; // 剩余边数
    // 拓扑排序，去掉没有金币的子树
    std::vector<int> q;
    for (int i = 0; i < n; i++)
        if (deg[i] == 1 && coins[i] == 0) // 没有金币的叶子
            q.push_back(i);
    while (!q.empty()) {
        left_edges--; // 删除节点 x（到其父节点的边）
        int x = q.back(); q.pop_back();
        for (int y: g[x])
            if (--deg[y] == 1 && coins[y] == 0) // 没有金币的叶子
                q.push_back(y);
    }

    // 再次拓扑排序
    for (int i = 0; i < n; i++)
        if (deg[i] == 1 && coins[i]) // 有金币的叶子（判断 coins[i] 是避免把没有金币的叶子也算进来）
            q.push_back(i);
    left_edges -= q.size(); // 删除所有叶子（到其父节点的边）
    for (int x: q) // 遍历所有叶子
        for (int y: g[x])
            if (--deg[y] == 1) // y 现在是叶子了
                left_edges--; // 删除 y（到其父节点的边）
    return std::max(left_edges * 2, 0);
}

