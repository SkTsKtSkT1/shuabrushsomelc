//
// Created by 25467 on 2023/6/22.
//

#include "mianshi_16_19.h"
#include "queue"
#include "functional"
#include "algorithm"

std::vector<int> mianshi_16_19::pondSizes(std::vector<std::vector<int>> &land) {
    int m = land.size(), n = land[0].size();

    std::function<int(int, int)> bfs = [&](int i, int j) -> int {
        if(i < 0 || i >= m || j < 0 || j>= n || land[i][j] != 0){
            return 0;
        }
        land[i][j] = 1;
        int res = 1;
        for(int k = 0; k < 8; ++k){
            res += bfs(i + x_dir[k], j + y_dir[k]);
        }
        return res;
    };

    std::vector<int> ans;
     for(int i = 0; i < m; ++i){
         for(int j = 0; j < n; ++j){
             if(land[i][j] == 0){
                 ans.push_back(bfs(i, j));
             }
         }
     }
    std::sort(ans.begin(), ans.end(), [&](int i, int j) -> bool {
        return i < j;
    });
    return ans;
}
