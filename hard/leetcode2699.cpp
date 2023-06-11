//
// Created by 25467 on 2023/6/9.
//

#include "leetcode2699.h"
#include "functional"
#include "cstring"
using std::vector;

std::vector<std::vector<int>>
leetcode2699::modifiedGraphEdges(int n, std::vector<std::vector<int>> &edges, int source, int destination, int target) {
    vector<std::pair<int, int>> g[n];
    for(int i = 0; i < edges.size(); i++){
        int x = edges[i][0], y = edges[i][1];
        g[x].emplace_back(y,i);
        g[y].emplace_back(x,i);// 建图，额外记录边的编号
    }

    int dis[n][2], delta, vis[n];
    std::memset(dis, 0x3f, sizeof(dis));
    dis[source][0] = dis[source][1] = 0;

    std::function<void(int)> dijkstra = [&](int k) -> void{
        for(int i = 0; i < n ; i++){
            vis[i] = 0;
        }
        for(;;){
            int x = -1;
            for(int i = 0; i < n; ++i){
                if(!vis[i] && (x < 0 || dis[i][k] < dis[x][k])){
                    x = i;
                }
            }
            if(x == destination) return;
            vis[x] = true;
            for(auto [y, eid]: g[x]){
                int wt = edges[eid][2];
                if(wt == -1){
                    wt = 1;
                }
                if(k == 1 && edges[eid][2] == -1){
                    int w = delta + dis[y][0] - dis[x][1];
                    if(w > wt){
                        edges[eid][2] = wt = w;
                    }
                }
                dis[y][k] = std::min(dis[y][k], dis[x][k] + wt);
            }
        }
    };
    dijkstra(0);
    delta = target - dis[destination][0];
    if(delta < 0){
        return {};
    }
    dijkstra(1);
    if(dis[destination][1] < target){
        return {};
    }

    for(auto &e:edges){
        if(e[2] == -1){
            e[2] = 1;
        }
    }
    return edges;
}
