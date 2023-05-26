//
// Created by 25467 on 2023/5/26.
//

#ifndef ALGORITHM_LEETCODE1091_H
#define ALGORITHM_LEETCODE1091_H
#include "vector"

class leetcode1091 {
public:
    int x_dir[8] = {-1, 1 ,0, 0,1,1,-1,-1};
    int y_dir[8] = {0, 0, -1, 1,1,-1,1,-1};
    int shortestPathBinaryMatrix(std::vector<std::vector<int>>& grid);
};


#endif //ALGORITHM_LEETCODE1091_H
