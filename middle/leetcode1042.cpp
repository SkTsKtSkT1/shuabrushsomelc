//
// Created by 25467 on 2023/4/15.
//

#include "leetcode1042.h"
//问题相当于用 4 种颜色给图中的每个节点染色，要求相邻节点颜色不同。而「所有花园最多有 3 条路径可以进入或离开」，这相当于图中每个点的度数至多为
//3，那么只要选一个和邻居不同的颜色即可。
//链接：https://leetcode.cn/problems/flower-planting-with-no-adjacent/solution/liang-chong-xie-fa-ha-xi-biao-shu-zu-wei-7hm8/

vector<int> leetcode1042::gardenNoAdj(int n, vector<vector<int>> &paths) {
    vector<vector<int>> g(n);
    for(auto& path:paths){
        int x= path[0]-1,y=path[1]-1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> color(n);
    for(int i=0;i<n;i++){
        bool used[5]{};
        for(int j:g[i]){
            used[color[j]]=true;
        }
        for(int k=1;k<5;k++){
            if(!used[k]){
                color[i]=k;
                break;
            }
        }
    }
    return color;
}
