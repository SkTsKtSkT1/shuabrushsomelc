//
// Created by skt on 2022/11/10.
//

#include "leetcode864.h"
#include "queue"
int leetcode864::shortestPathAllKeys(vector<std::string> &grid) {
    //using a int to represents the keys
    //int keyState=0; // 00000000
    int m=grid.size();
    int n=grid[0].size();
    int startX=0,startY=0;
    int keyNum=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='@'){
                startX=i;
                startY=j;
            }else if(std::islower(grid[i][j])){
                keyNum++;
            }
        }
    }

    std::queue<std::tuple<int,int,int>> state{{{startX,startY,0}}};// x,y,keyState
    //由于可以掉头，因此使用x y state作为一个visit数组
    vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(1<<keyNum,0)));
    vis[startX][startY][0]=1;
    int ans=0;
    while(!state.empty()){
        for(int t=state.size();t;--t)
        {
            auto [x,y,s] = state.front();
            state.pop();
            if (s == (1 << keyNum) - 1) return ans;
            for (int p = 0; p < 4; ++p) {
                int xNew = x + xDir[p], yNew = y + yDir[p];
                if (xNew >= 0 && xNew < m && yNew >= 0 && yNew < n && grid[xNew][yNew]!='#') {
                    char c=grid[xNew][yNew];
                    if (std::isupper(c) && (s >> (c-'A') & 1) == 0)
                        continue;
                    int tempState = s;
                    if (std::islower(c)) {
                        tempState |= (1 << (c - 'a'));
                    }
                    if (!vis[xNew][yNew][tempState]) {
                        state.emplace(xNew, yNew, tempState);
                        vis[xNew][yNew][tempState] = 1;
                    }
                }
            }
        }
        ++ans;
    }
    return -1;
}