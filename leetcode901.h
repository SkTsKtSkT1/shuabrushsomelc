//
// Created by skt on 2022/10/21.
//

#ifndef ALGORITHM_LEETCODE901_H
#define ALGORITHM_LEETCODE901_H
#include "stack"


class StockSpanner {
private:
    std::stack<std::pair<int,int>> priceAndWeight;
    int index;
public:
    StockSpanner();

    int next(int price);
};


#endif //ALGORITHM_LEETCODE901_H
