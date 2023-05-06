//
// Created by 25467 on 2023/5/6.
//

#include "leetcode1419.h"
#include "unordered_map"
////每一只青蛙可以处于5种状态，即c,r,o,a,k(不鸣叫和鸣叫结束都处于k)
////每个字符视为状态，由前一个字符转移而来，例如，遇到o，则需要将r-1，o+1
////无法转移时，如果当前字符为c，则可以增加一只青蛙，否则失败
////最终所有青蛙都要回到不鸣叫的状态，否则失败
int leetcode1419::minNumberOfFrogs(string croakOfFrogs) {
    int status[5]={0}, ans=0;
    std::unordered_map<char,int> u_map{{'c',0},{'r',1},{'o',2},{'a',3},{'k',4}};
    for(char& c:croakOfFrogs){ // trans from 'k' and end by 'k'
        if(c=='c'){ //if 'c' then can add frog
            if(status[4]){ //if current is 'c' and k!=0, so the frog is already finish
                ++status[0];
                --status[4];
            }else{
                ++ans;
                ++status[0];
            }
        }else{
            if(status[u_map[c]-1]){
                --status[u_map[c]-1];
                ++status[u_map[c]];
            }else{
                return -1;
            }
        }
    }
    return status[4]==ans?ans:-1;
}
