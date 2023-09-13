//
// Created by 25467 on 2023/9/13.
//

#ifndef ALGORITHM_LEETCODE2596_H
#define ALGORITHM_LEETCODE2596_H

#include <vector>
class leetcode2596 {
private:
    const int dir_x[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int dir_y[8] = {1, -1, 2, -2, 2, -2, 1, -1};
public:
    bool checkValidGrid(std::vector<std::vector<int>>& grid);
};


#endif //ALGORITHM_LEETCODE2596_H
