//
// Created by 25467 on 2023/7/16.
//

#include <functional>
#include "leetcode834.h"
//https://leetcode.cn/problems/sum-of-distances-in-tree/solutions/2345592/tu-jie-yi-zhang-tu-miao-dong-huan-gen-dp-6bgb/
//脑子疼 学不会了
std::vector<int> leetcode834::sumOfDistancesInTree(int n, std::vector<std::vector<int>> &edges) {
    std::vector<std::vector<int>> g(n);
    for(auto& e : edges){
        int x = e[0], y = e[1];
        g[x].push_back(y);
        g[y].push_back(x);
    }

    std::vector<int> ans(n);
    std::vector<int> size(n, 1);
    std::function<void(int, int, int)> dfs = [&](int x, int fa, int depth) -> void{
        ans[0] += depth;
        for(int y : g[x]){
            if(y != fa){
                dfs(y, x, depth + 1);
                size[x] += size[y];
            }
        }
    };
    dfs(0, -1, 0);

    std::function<void(int, int)> reroot = [&](int x, int fa) -> void{
        for(int y : g[x]){
            if(y != fa){
                ans[y] = ans[x] + n - 2 * size[y];
                reroot(y, x);
            }
        }
    };
    reroot(0, -1);
    return ans;
}
