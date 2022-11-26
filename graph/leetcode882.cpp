//
// Created by lzw on 2022/11/26.
//

#include "leetcode882.h"
#include "algorithm"

int leetcode882::reachableNodes(vector<vector<int>> &edges, int maxMoves, int n) {
    vector<vector<pair<int, int>>> g(n);
    for (auto &e: edges) {
        int u = e[0], v = e[1], cnt = e[2];
        g[u].emplace_back(v, cnt + 1);
        g[v].emplace_back(u, cnt + 1); // 建图
    }

    auto dist = dijkstra(g, 0); // 从 0 出发的最短路

    int ans = 0;
    for (int d : dist)
        if (d <= maxMoves) // 这个点可以在 maxMoves 步内到达
            ++ans;
    for (auto &e: edges) {
        int u = e[0], v = e[1], cnt = e[2];
        int a = std::max(maxMoves - dist[u], 0);
        int b = std::max(maxMoves - dist[v], 0);
        ans += std::min(a + b, cnt); // 这条边上可以到达的节点数
    }
    return ans;
}

vector<int> leetcode882::dijkstra(vector<vector<pair<int, int>>> &g, int start) {
    vector<int> dist(g.size(), INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, std::greater<>> pq;
    pq.emplace(0, start);
    while (!pq.empty()) {
        auto[d, x] = pq.top();
        pq.pop();
        if (d > dist[x]) continue;
        for (auto[y, wt] : g[x]) {
            int new_d = dist[x] + wt;
            if (new_d < dist[y]) {
                dist[y] = new_d;
                pq.emplace(new_d, y);
            }
        }
    }
    return dist;
}