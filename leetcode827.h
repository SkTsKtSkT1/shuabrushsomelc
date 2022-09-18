//
// Created by lzw on 2022/9/18.
//

#ifndef ALGORITHM_LEETCODE827_H
#define ALGORITHM_LEETCODE827_H
#include "vector"
#include "unordered_map"
#include "unordered_set"
using std::vector;

class leetcode827 {
private:
    //深度优先遍历
    /*!
     *
     * @param x     x
     * @param y     y
     * @param grid  map
     * @param mark  markIndex
     */
    void dfs(int x,int y,vector<vector<int>>& grid,int mark);
    //search direction
    const int dx[4]={0,1,0,-1};
    const int dy[4]={1,0,-1,0};
    int count;//return area
public:
    int largestIsland(vector<vector<int>>& grid);
};


#endif //ALGORITHM_LEETCODE827_H
