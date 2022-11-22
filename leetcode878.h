//
// Created by lzw on 2022/11/22.
//

#ifndef ALGORITHM_LEETCODE878_H
#define ALGORITHM_LEETCODE878_H

#include "vector"
class leetcode878 {
private:
    int gcb(int a,int b);
    int lcm(int a ,int b);
    long check(long x,int a,int b);
public:
    int nthMagicalNumber(int n, int a, int b);
};


#endif //ALGORITHM_LEETCODE878_H
