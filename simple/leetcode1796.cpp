//
// Created by lzw on 2022/12/3.
//

#include "leetcode1796.h"


int leetcode1796::secondHighest(string s) {
    char max='0'-1;
    char second='0'-1;
    for(const char & c:s){
        if(c<'0'|| c>'9') continue;
        if(c>max){
            second=max;
            max=c;
        }else if(c==max){
            continue;
        }
        else if(c>second){
            second=c;
        }
    }
    if(max==second) return -1;
    return second-'0';
}