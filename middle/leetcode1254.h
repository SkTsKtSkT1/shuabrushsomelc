//
// Created by skt on 2023/6/18.
//

#ifndef ALGORITHM_LEETCODE1254_H
#define ALGORITHM_LEETCODE1254_H

#include "vector"

class leetcode1254 {
private:
    void dfs(std::vector<std::vector<int>>& grid, int i, int j);
public:
    int closedIsland(std::vector<std::vector<int>>& grid);

};


#endif //ALGORITHM_LEETCODE1254_H
