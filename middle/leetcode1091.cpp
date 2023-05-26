//
// Created by 25467 on 2023/5/26.
//

#include "leetcode1091.h"
#include "queue"
using std::queue;
using std::vector;
int leetcode1091::shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid) {
    if(grid.size()==0 || grid.empty()){
        return -1;
    }
    if(grid[0][0] == 1){
        return -1;
    }
    int n = grid.size();
    queue<vector<int>> q;
    q.push({0,0});
    grid[0][0] = 1;
    int path = 1;
    while(!q.empty()){
        int size = q.size();
        while(size-- > 0){
            vector<int> cur = q.front();
            q.pop();
            int x = cur[0];
            int y = cur[1];
            if(x==n-1 && y==n-1){
                return path;
            }
            for(int i = 0; i<8; i++){
                int x1 = x + x_dir[i];
                int y1 = y + y_dir[i];
                if(x1<0 || x1>=n || y1<0 || y1>=n || grid[x1][y1] == 1){
                    continue;
                }
                q.push({x1,y1});
                grid[x1][y1] = 1;
            }
        }
        path++;
    }
    return -1;

}
