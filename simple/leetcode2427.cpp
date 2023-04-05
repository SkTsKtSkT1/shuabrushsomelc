//
// Created by 25467 on 2023/4/5.
//

#include "leetcode2427.h"

int leetcode2427::commonFactors(int a, int b) {
    int max_factor=gcd(a,b);
    int res=0;
    for(int i=1;i<=max_factor;i++){
        if(a%i==0 && b%i==0){
            res++;
        }
    }
    return res;
}


int leetcode2427::gcd(int a, int b) {
    return b? gcd(a,a%b):a;
}