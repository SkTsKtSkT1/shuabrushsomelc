//
// Created by skt on 2023/6/12.
//

#ifndef ALGORITHM_LEETCODE1483_H
#define ALGORITHM_LEETCODE1483_H
#include "vector"

class TreeAncestor {
private:
    std::vector<std::vector<int>> dp;
public:
    TreeAncestor(int n, std::vector<int>& parent);


    int getKthAncestor(int node, int k);

};


#endif //ALGORITHM_LEETCODE1483_H
