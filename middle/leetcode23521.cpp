//
// Created by 25467 on 2023/6/6.
//

#include "leetcode23521.h"
#include "map"

int leetcode23521::equalPairs11(vector<vector<int>> &grid) {
    std::map<vector<int>, int> m1;
    std::map<vector<int>, int> m2;
    for(int i = 0;i < grid.size(); i++){
        m1[grid[i]]++;
    }
    for(int i = 0;i < grid.size(); i++){
        for(int j = 0; j <= i; ++j){
            std::swap(grid[i][j], grid[j][i]);
        }
    }
    for(int i = 0; i< grid.size(); i++){
        m2[grid[i]]++;
    }
    int res = 0;
    for(auto& c : m1){
        if(m2[c.first] > 0){
            res += c.second * m2[c.first];
        }
    }
    return res;
}
