//
// Created by lzw on 2022/9/13.
//

#include "leetcode670.h"

int leetcode670::maximumSwap(int num) {
    if (num<=9) return num;
    string numS= std::to_string(num);
    int len=numS.size();
    //记录每个数字最后一次出现在哪里
    vector<int> pos(10,-1);
    for(int i=0;i<len;i++){
        pos[numS[i]-'0']=i;
    }
    //把靠右的大数与靠左的小数字进行交换
    for(int i=0;i<len;i++){
        for(int j=9;j>=0;j--){
            if(numS[i]-'0' < j &&  pos[j]>i){
                std::swap(numS[i],numS[pos[j]]);
                return std::stoi(numS);
            }
        }
    }
    return num;

}