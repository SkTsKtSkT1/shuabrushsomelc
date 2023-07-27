//
// Created by 25467 on 2023/7/27.
//

#include "leetcode2500.h"
#include "algorithm"
int leetcode2500::deleteGreatestValue(std::vector<std::vector<int>> &grid) {
    int res = 0;
    for(std::vector<int>& g : grid){
        std::sort(g.begin(), g.end(), [](int a, int b)->bool {
           return a > b; // from big to small
        });
    }
    //加上每一列的最大值
    for(int j = 0; j < grid[0].size(); ++j){
        int tmp = 0;
        for(int i = 0; i < grid.size(); ++i){
            tmp = std::max(tmp, grid[i][j]);
        }
        res += tmp;
    }
    return res;
}
