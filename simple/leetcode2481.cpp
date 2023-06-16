//
// Created by skt on 2023/6/17.
//

#include "leetcode2481.h"

int leetcode2481::numberOfCuts(int n) {
    if (n == 1) {
        return 0;
    }
    if ((n & 1) == 0) {
        return n / 2;
    } else {
        return n;
    }
}
