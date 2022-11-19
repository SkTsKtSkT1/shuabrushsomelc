//
// Created by lzw on 2022/11/19.
//

#include "leetcode1732.h"

int leetcode1732::largestAltitude(vector<int> &gain) {
    int ans=0;
    int cur=0;
    for(int& g:gain){
        cur+=g;
        ans=(ans>cur?ans:cur);
    }
    return  ans;
}