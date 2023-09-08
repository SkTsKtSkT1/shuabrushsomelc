//
// Created by skt on 2023/9/9.
//

#include "leetcode207.h"
#include <queue>
/*
 * 为了方便，我们记 numCourses 为 n，prerequisites 为 g。
若课程 a 存在前置课程 b 的话，我们添加一条从 b 到 a 的有向边，同时统计所有点的入度。
当处理完所有的 g[i]g[i]g[i] 后，将所有的入度为 000 的课程（含义为没有前置课程要求的科目）进行入队操作，
 跑一遍「拓扑排序」，若所有课程都能顺利出队，说明所有课程都能使完成。
//https://blog.csdn.net/lisonglisonglisong/article/details/45543451
 拓扑排序就是每次输出一个入度为0 的节点。
 可以使用队列，每次去掉该输出节点导致的入度
 */
bool leetcode207::canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector<int> deg(numCourses, 0);//统计入度
    std::vector G(numCourses, std::vector<int>{});//directed graph

    int n = prerequisites.size();
    for(const auto& pre : prerequisites){
        //pre[1]->pre[0]
        G[pre[1]].push_back(pre[0]);
        deg[pre[0]]++;
    }

    std::queue<int> q;
    for(int i = 0; i < numCourses; ++i){
        if(deg[i] == 0){
            q.push(i);
        }
    }
    int cnt = 0;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cnt++;
        for(auto g : G[f]){
            if(--deg[g] == 0){
                q.push(g);
            }
        }
    }
    return cnt == numCourses;
}
