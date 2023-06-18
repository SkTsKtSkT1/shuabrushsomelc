//
// Created by lzw on 2022/10/20.
//

#include "leetcode779.h"

int leetcode779::kthGrammar(int n, int k) {
    if(n==1) return 0;
    int bef=0;
    if(k%2==0) bef=kthGrammar(n-1,k/2);
    else bef=kthGrammar(n-1,k/2+1);
    if(bef==0){
        if(k%2==0) return 1;
        else return 0;
    } else if(bef==1){
        if(k%2==0) return 0;
        else return 1;
    }else{
        return -1;
    }
}