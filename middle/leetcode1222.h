//
// Created by 25467 on 2023/9/14.
//

#ifndef ALGORITHM_LEETCODE1222_H
#define ALGORITHM_LEETCODE1222_H

#include <vector>
class leetcode1222 {
private:
    const int x_dir[8] = {-1, -1, -1, 0, 0, 1, 1 , 1};
    const int y_dir[8] = {0, -1, 1, -1, 1, 0, -1, 1};
public:
    std::vector<std::vector<int>> queensAttacktheKing(std::vector<std::vector<int>>& queens, std::vector<int>& king);
};


#endif //ALGORITHM_LEETCODE1222_H
