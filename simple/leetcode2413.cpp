//
// Created by 25467 on 2023/4/21.
//

#include "leetcode2413.h"
int  leetcode2413::gcd(int a,int b){
    return b? gcd(b,a%b):a;
}

int leetcode2413::smallestEvenMultiple(int n) {
    return 2*n/gcd(2,n);

}

