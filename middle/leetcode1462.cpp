//
// Created by 25467 on 2023/9/12.
//

#include "leetcode1462.h"

std::vector<bool> leetcode1462::checkIfPrerequisite(int numCourses, std::vector<std::vector<int>> &prerequisites,
                                                    std::vector<std::vector<int>> &queries) {
    std::vector<std::vector<int>> G(numCourses, std::vector<int>(numCourses, 0));
    for(auto& e : prerequisites){
        G[e[0]][e[1]] = 1;
    }
    // 2. dp[i][j]此时为从i到j是否有路径，分为两种情况：
    //    (1)、有边 i -> j，i可以直接到j，要求 dp[i][j] 为 true
    //    (2)、无边 i -> j，i可以通过k到j，那么要求 dp[i][k] && dp[k][j] 为 true
    //    出于节省空间可以直接在图数组g中进行动态规划
    for(int k = 0; k < numCourses; ++k){
        for(int i = 0; i < numCourses; ++i){
            for(int j = 0; j < numCourses; ++j){
                G[i][j] = G[i][j] || (G[i][k] && G[k][j]);
            }
        }
    }
    std::vector<bool> res;
    for(auto& q : queries){
        res.emplace_back(G[q[0]][q[1]]);
    }
    return res;
}
