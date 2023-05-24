//
// Created by 25467 on 2023/5/24.
//

#include "leetcode1377.h"
#include "functional"
using std::vector;

double leetcode1377::frogPosition(int n, std::vector<std::vector<int>> &edges, int t, int target) {
    vector<vector<int>> g(n+1);
    g[1] = {0}; //add a "0" point as the "1" neighbor
    for(vector<int> &e : edges){
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }
    std::function<long long(int ,int, int)> dfs = [&](int x, int fa, int left_t)-> long long{
        if(left_t == 0) return x==target;
        if(x == target) return g[x].size() == 1;
        for(int y: g[x]){
            if(y != fa){//y不能为根节点
                long long prod = dfs(y, x, left_t - 1);
                if(prod) return prod*(g[x].size()-1);
            }
        }
        return 0;
    };
    long long prod = dfs(1,0,t);
    return prod ? 1.0/prod:0;
}
