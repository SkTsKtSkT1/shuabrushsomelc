//
// Created by skt on 2023/8/4.
//

#ifndef ALGORITHM_LEETCODE980_H
#define ALGORITHM_LEETCODE980_H

#include "vector"
class leetcode980 {
private:
    int dir[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
public:
    int uniquePathsIII(std::vector<std::vector<int>>& grid);
};


#endif //ALGORITHM_LEETCODE980_H
