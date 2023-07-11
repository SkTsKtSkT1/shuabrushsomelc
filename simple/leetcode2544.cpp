//
// Created by skt on 2023/7/12.
//

#include "leetcode2544.h"

int leetcode2544::alternateDigitSum(int n) {
    int cnt = 0;//the length of n
    int res = 0;
    int sig = 1;
    while(n){
        res = res +  sig * (n % 10);
        sig *= -1;
        ++cnt;
        n /= 10;
    }
    return cnt % 2 ? res : -res;
}
