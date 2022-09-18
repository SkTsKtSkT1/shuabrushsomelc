//
// Created by lzw on 2022/9/18.
//

#include "leetcode827.h"

void leetcode827::dfs(int x, int y, vector<vector<int>> &grid, int mark) {
    if (grid[x][y] == mark || grid[x][y] == 0) return;
    grid[x][y] = mark;
    count++;
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX < 0 || nextY < 0 || nextX >= grid.size() || nextY >= grid[0].size()) continue;
        dfs(nextX,nextY,grid,mark);
    }
}

int leetcode827::largestIsland(vector<vector<int>> &grid) {
    int n=grid.size(),m=grid[0].size();
    std::unordered_map<int,int> gridMark;  //mark->count
    int mark=2;
    bool isFull=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0) isFull=false;
            if(grid[i][j]!=mark && grid[i][j]==1){
                count=0;
                dfs(i,j,grid,mark);
                gridMark[mark]=count;
                mark++;
            }
        }
    }
    //return
    if(isFull)  return n*m;

    int ans=0;
    std::unordered_set<int> visitedMark;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            int count = 1; //0->1
            visitedMark.clear();
            if (grid[i][j] == 0) {
                for (int k = 0; k < 4; k++) {
                    int nextI = i + dx[k];
                    int nextJ = j + dy[k];
                    if (nextI < 0 || nextJ < 0 || nextI >= n || nextJ >= m) continue;
                    if (visitedMark.count(grid[nextI][nextJ])) continue;
                    count += gridMark[grid[nextI][nextJ]];
                    visitedMark.insert(grid[nextI][nextJ]);
                }
            }
            ans = std::max(ans, count);
        }
    }
    return ans;
}