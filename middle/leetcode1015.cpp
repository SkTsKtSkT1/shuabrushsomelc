//
// Created by 25467 on 2023/5/10.
//

#include "leetcode1015.h"
////设n=p*K+q
////则n*10+1=10*p*K+q*10+1;
////有n%K=q
////有(n*10+1)%K=(10*p*K+q*10+1)%K=(q*10+1)%K
////又((n%K)*10+1)%K=(q*10+1)%K
////推断出：(n*10+1)%K = ((n%K)*10+1)%K
int leetcode1015::smallestRepunitDivByK(int k) {
    if(k%2==0 || k%5==0) return -1;// if odd return -1;
    // for k there exists n mod k = i, i=0,...k-1;
    int p=0;
    for(int i=1;i<=k;i++){
        p=(p*10+1)%k; //由于上述公式，原本应该构造n个1组成的（10*n+1)  对k求mod 等同于(n%k)*10+1 对k求mod
        if(p==0) return i;
    }
    return -1;
}
