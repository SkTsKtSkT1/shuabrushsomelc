//
// Created by skt on 2023/8/24.
//

#include "leetcode1267.h"
#include <cstring>

int leetcode1267::countServers(std::vector<std::vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    int serverCnt = 0;
    int serverRow[m], serverCol[n];
    std::memset(serverCol, 0, sizeof(serverCol));
    std::memset(serverRow, 0, sizeof(serverRow));

    //if row = 2 or col = 2 is ok
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1){
                serverCnt += 1;
                serverRow[i] += 1;
                serverCol[j] += 1;
            }
        }
    }
    int unable = 0; //或者直接用 >= 2 || >= 2 统计可以的也可以
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(grid[i][j] == 1 && serverRow[i] < 2 && serverCol[j] < 2){
                unable += 1;
            }
        }
    }

    return serverCnt - unable;
}
