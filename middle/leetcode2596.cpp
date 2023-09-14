//
// Created by 25467 on 2023/9/13.
//

#include "leetcode2596.h"

bool leetcode2596::checkValidGrid(std::vector<std::vector<int>> &grid) {
    if(grid[0][0] != 0){
        return false;
    }
    int n = grid.size();
    int end = n * n - 1;
    int i = 0;
    int cur_x = 0, cur_y = 0;
    for(int k = 0; k <= end; ++k){
        bool changed = false;
        for(int j = 0; j < 8; ++j){
            int new_x = cur_x + dir_x[j];
            int new_y = cur_y + dir_y[j];
            if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= n){
                continue;
            }
            if(grid[new_x][new_y] == i + 1){
                i += 1;
                cur_x = new_x;
                cur_y = new_y;
                changed = true;
            }
        }
        if(!changed){
            return false;
        }
    }
    return grid[cur_x][cur_y] == end;


}
