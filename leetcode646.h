//
// Created by Administrator on 2022/9/3.
//

#ifndef SHUABRUSHSOMELC_LEETCODE646_H
#define SHUABRUSHSOMELC_LEETCODE646_H

#include "vector"
#include "algorithm"
#include "iostream"

class leetcode646{
public:
    int findLongestChain(std::vector<std::vector<int>>& pairs);

    static bool cmp(const std::vector<int>& a,const std::vector<int>& b);
};


#endif //SHUABRUSHSOMELC_LEETCODE646_H
