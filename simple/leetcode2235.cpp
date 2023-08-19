//
// Created by 25467 on 2023/8/19.
//

#include "leetcode2235.h"

int leetcode2235::sum(int num1, int num2) {
    while(num2 != 0){
        int carry = (num1 & num2) << 1; //考虑到进位
        num1 = num1 ^ num2; //不考虑进位相加
        num2 = carry;
    }
    return num1;
}
