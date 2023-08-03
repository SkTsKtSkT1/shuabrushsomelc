//
// Created by skt on 2023/8/4.
//

#include "leetcode980.h"
#include "functional"
int leetcode980::uniquePathsIII(std::vector<std::vector<int>> &grid) {
    int r = grid.size(), c = grid[0].size();
    int si = 0, sj =0, n =0;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(grid[i][j] == 0){
                n++;
            }else if(grid[i][j] == 1){
                n++;
                si = i;
                sj = j;
            }
        }
    }

    std::function<int(int, int, int)> dfs = [&](int i, int j, int n) -> int{
        if(grid[i][j] == 2){
            if(n == 0){
                return 1;
            }else{
                return 0;
            }
        }

        int t = grid[i][j], res = 0;
        grid[i][j] = -1;
        for(int d = 0; d < 4; ++d){
            int ni = i + dir[0][d];
            int nj = j + dir[1][d];
            if(ni >= 0  && ni < r && nj >= 0 && nj < c && (grid[ni][nj] == 0 || grid[ni][nj] == 2)){
                res += dfs(ni, nj, n - 1);
            }
        }
        grid[i][j] = t;
        return res;
    };
    return  dfs(si, sj, n);
}
