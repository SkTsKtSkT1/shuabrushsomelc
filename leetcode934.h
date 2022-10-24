//
// Created by skt on 2022/10/25.
//

#ifndef ALGORITHM_LEETCODE934_H
#define ALGORITHM_LEETCODE934_H
#include "vector"
#include "queue"

using std::vector;

class leetcode934 {
private:
    int xDir[4]={1,-1,0,0};
    int yDir[4]={0,0,-1,1};
    std::queue<std::pair<int,int>> seaPoints;
    void dfs(vector<vector<int>>& grid,int i,int j);
public:
    int shortestBridge(vector<vector<int>>& grid);
};


#endif //ALGORITHM_LEETCODE934_H
