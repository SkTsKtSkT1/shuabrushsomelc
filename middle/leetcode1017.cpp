//
// Created by 25467 on 2023/4/6.
//

#include "leetcode1017.h"

// 19/-9 = -2 mod 1;
//-2 / -9 =1 mod 7; 保证余数为正

string leetcode1017::baseNeg2(int n) {
    if(n==0) return "0";
    string res;

    while(n!=0){
        int r = n % (-2);

        r = (r + abs(-2))%abs(-2);
        res = std::to_string(r) + res;
        n = (n-r)/(-2);

    }
    return res;
}

string leetcode1017::baseNegM(int n, int m) {
    if(n==0) return "0";
    if(m==0) return "error, m is 0!";

    string res;

    while(n!=0){
        int r = n%m;
        r = (r+abs(m))%abs(m);
        res = std::to_string(r) + res;
        n=(n-r)/m;
    }

    return res;
}