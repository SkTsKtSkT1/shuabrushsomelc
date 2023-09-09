//
// Created by skt on 2023/9/10.
//

#include "leetcode210.h"
#include <queue>

std::vector<int> leetcode210::findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
    std::vector G(numCourses, std::vector<int>{});
    std::vector<int> deg(numCourses, 0);
    for(const auto& pre : prerequisites){
        G[pre[1]].push_back(pre[0]); //pre[1] -> pre[0];
        deg[pre[0]] += 1;
    }

    std::vector<int> res;
    std::queue<int> q;
    for(int i = 0; i < numCourses; ++i){
        if(deg[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int course = q.front();
        res.push_back(course);
        q.pop();
        for(auto g : G[course]){ //对于这个点，如果他后继的度为0，说明可以学习
            if(--deg[g] == 0){
                q.push(g);
            }
        }
    }

    return res.size() == numCourses ? res : std::vector<int>();
}
