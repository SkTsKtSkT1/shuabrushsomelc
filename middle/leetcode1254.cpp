//
// Created by skt on 2023/6/18.
//

#include "leetcode1254.h"

//https://leetcode.cn/problems/number-of-closed-islands/solution/liang-chong-si-lu-xian-wai-hou-nei-chu-j-b1e4/
int leetcode1254::closedIsland(std::vector<std::vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    //先对边界的进行处理，也就是把边界上的0以及相连的全部修改为1
    for(int i = 0; i < m; i++){
        // 如果是第一行和最后一行，访问所有格子
        // 如果不是，只访问第一列和最后一列的格子
        int step = ((i==0 || i == m-1) ? 1 : n-1);
        for(int j = 0; j < n; j += step){
            dfs(grid, i, j);
        }
    }

    int ans = 0;
    for(int i = 1; i < m - 1; i++){
        for(int j = 1; j < n - 1; j++){
            if(grid[i][j] == 0){
                //此时若存在里面的0，一定是closed的，并且需要把相连的都改成1，表示已经统计了
                ans++;
                dfs(grid, i , j);
            }
        }
    }
    return ans;
}

void leetcode1254::dfs(std::vector<std::vector<int>> &grid, int i, int j) {
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j]){
        return;
    }
    grid[i][j] = 1;
    dfs(grid, i , j - 1);
    dfs(grid, i , j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
}
