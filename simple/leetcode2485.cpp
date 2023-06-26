//
// Created by 25467 on 2023/6/26.
//

#include "leetcode2485.h"
#include "cmath"

int leetcode2485::pivotInteger(int n) {
    // [1,x] = [x,n] -> [1,x) = (x,n];
    float res = std::sqrt(n * (n + 1) / 2);
    if(res == (int)res)return res;
    return -1;;
}
