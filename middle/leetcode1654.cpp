//
// Created by skt on 2023/8/30.
//

#include "leetcode1654.h"
#include <cstring>
#include <algorithm>
#include <queue>
//注意为了避免两次后跳，我们需要在 BFS 中保存上一次是前跳还是后跳。
//如果是后跳到达的节点i，不需要记录为已访问（如果这个点我是向右跳到达的，
// 那必然没有什么问题，因为存在向左向右两种情况；但是如果我这个点是向左跳到的，那么就会有问题了
// ，因为向左跳到这个点的话那么我只有向右跳一种方法，但是如果我下一次我又向右到达了这个点，那么就会多出向左跳这一种情况，)
int leetcode1654::minimumJumps(std::vector<int> &forbidden, int a, int b, int x) {
    int F = *std::max_element(forbidden.begin(), forbidden.end());
    int bound = std::max(F + a + b, x + b);
    int f[bound + 1];
    memset(f, 0, sizeof(f));
    for(int i : forbidden){
        f[i] = 1;
    }

    int dist[bound + 1][2]; // dist[i][0] - 上一次前跳, dist[i][1] - 上一次后跳
    memset(dist, 0x3f, sizeof(dist));
    dist[0][0] = 0;
    std::queue<std::pair<int,int>> q({{0, 0}});

    while(!q.empty()){
        auto [i, pre] = q.front(); q.pop();
        if(i == x) {
            return dist[i][pre];
        }
        if(pre == 0 && i-b >= 0 && !f[i-b] && dist[i][pre] + 1 < dist[i-b][1]) {
            dist[i-b][1] = dist[i][pre] + 1;
            q.emplace(i-b, 1);
        }
        if(i+a <= bound && !f[i+a] && dist[i][pre] + 1 < dist[i+a][0]) {
            dist[i+a][0] = dist[i][pre] + 1;
            q.emplace(i+a, 0);
        }
    }
    return -1;
}
