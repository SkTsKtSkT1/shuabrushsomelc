//
// Created by skt on 2022/10/25.
//

#include "leetcode934.h"

int leetcode934::shortestBridge(vector<vector<int>> &grid) {
    //1.search the boundary of each island,denoted by 1 and 2;
    //2.use dfs to find the first island and denoted it as 2, and store the '0' near island
    //3.use bfs to make sea to land,each time use each time add the next sea point,until get the next island
    int n=grid.size();
    int m=grid[0].size();
    bool isFind=false; //if  find the first island
    for(int i=0;i<n;i++){
        if(isFind) break;
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                dfs(grid,i,j);
                isFind=true;
                break;
            }
        }
    }

    int ans=0;
    while(!seaPoints.empty()){
        int size=seaPoints.size();
        ans++;
        while(size--){
            //seaPoints coordination
            int x=seaPoints.front().first;
            int y=seaPoints.front().second;
            seaPoints.pop();
            //先把这个填为2，在加入其周围的海
            grid[x][y]=2;
            for(int k=0;k<4;k++){
                int dx=x+xDir[k];
                int dy=y+yDir[k];
                if(dx>=0 && dx<m && dy>=0 && dy<n){
                    if(grid[dx][dy]==2) continue;
                    else if(grid[dx][dy]==1) return ans;
                    else if(grid[dx][dy]==0) {
                        seaPoints.emplace(dx,dy);
                        grid[dx][dy]=2;//avoid some point be added more than once;
                    }
                }
            }
        }
        return ans;
    }
}


void leetcode934::dfs(vector<vector<int>> &grid, int i, int j) {
    grid[i][j]=2;
    for(int k=0;k<4;k++){
        int x=i+xDir[k];
        int y=j+yDir[k];
        if(x>=0 && x<grid[0].size() && y>=0 && y<grid.size()){
            if(grid[x][y]==2) continue;
            else if(grid[x][y]==1) dfs(grid,x,y);
            else if(grid[x][y]==0) seaPoints.emplace(x,y);
        }
    }
}

