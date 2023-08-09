//
// Created by 25467 on 2023/8/9.
//

#include "leetcode1281.h"

int leetcode1281::subtractProductAndSum(int n) {
    int dot = 1, sum = 0;
    while(n){
        int cur = n % 10;
        dot *= cur;
        sum += cur;
        n /= 10;
    }
    return dot - sum;
}
