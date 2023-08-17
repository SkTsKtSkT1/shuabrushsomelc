//
// Created by 25467 on 2023/8/17.
//

#ifndef ALGORITHM_LEETCODE1444_H
#define ALGORITHM_LEETCODE1444_H

#include <vector>
#include <string>

class leetcode1444 {
private:
    std::vector<std::vector<int>> sum;
public:
    int ways(std::vector<std::string>& pizza, int k);
    int query(int r1, int c1, int r2, int c2);
};


#endif //ALGORITHM_LEETCODE1444_H
