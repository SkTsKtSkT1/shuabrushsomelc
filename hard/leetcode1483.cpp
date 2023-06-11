//
// Created by skt on 2023/6/12.
//

#include "leetcode1483.h"
//Binary Lifting 的本质其实是 dp。dp[node][j] 存储的是 node 节点距离为 2^j 的祖先是谁。
//根据定义，dp[node][0] 就是 parent[node]，即 node 的距离为 1 的祖先是 parent[node]。
//状态转移是： dp[node][j] = dp[dp[node][j - 1]][j - 1]。
//意思是：要想找到 node 的距离 2^j 的祖先，先找到 node 的距离 2^(j - 1) 的祖先，然后，再找这个祖先的距离 2^(j - 1) 的祖先。两步得到 node 的距离为 2^j 的祖先。
//所以，我们要找到每一个 node 的距离为 1, 2, 4, 8, 16, 32, ... 的祖先，直到达到树的最大的高度。树的最大的高度是 logn 级别的。
//https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/solution/li-kou-zai-zhu-jian-ba-acm-mo-ban-ti-ban-shang-lai/

TreeAncestor::TreeAncestor(int n, std::vector<int> &parent) : dp(n){
    for(int i = 0; i < n; i++){
        dp[i].push_back(parent[i]);
    }
    for(int j = 1; ; j++){
        bool allneg = true;
        for(int i = 0; i < n; i++){
            int tmp = dp[i][j - 1] != -1 ? dp[dp[i][j - 1]][j - 1] : -1;
            dp[i].push_back(tmp);
            if(tmp != -1){
                allneg = false;
            }
        }
        if(allneg) break;
    }
}

int TreeAncestor::getKthAncestor(int node, int k) {
    int res = node, pos = 0;
    while(k && res != -1){
        if(pos >= dp[res].size()) return -1;
        if(k & 1) res = dp[res][pos];
        k >>= 1, pos ++;
    }
    return res;
//    if(k == 0 || node == -1){
//        return node;
//    }
//    int pos = ffs(k) - 1;
//    return pos < dp[node].size() ? getKthAncestor(dp[node][pos],k - (1 << pos)) : -1;
}
