//
// Created by lzw on 2022/10/31.
//

#include "leetcode481.h"
//https://leetcode.cn/problems/magical-string/solution/zhua-wa-mou-si-tu-jie-leetcode-by-muse-7-i2z6/
int leetcode481::magicalString(int n) {
    //以122开头进行拓展
    vector<int> magic(n+1);
    magic[0]=1;
    int tail=1,pos=1,res=1,value=1,count=2;
    while(tail<n){
        value^=3;//1和2交替出现
        while(count-- && tail<n){
            magic[tail++]=value;
            if(value==1) res++;
        }
        count=magic[++pos];
    }
    return  res;
}