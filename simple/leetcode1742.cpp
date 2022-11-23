//
// Created by lzw on 2022/11/23.
//

#include "leetcode1742.h"
#include "algorithm"
#include "iostream"
int sumNext(int num){
    //只要末尾的9
    int res=0;
    while(num!=0){
        if(num%10==9) res++;
        num/=10;
        if(num%10!=9) break;
    }
    return res;
}

int leetcode1742::countBalls(int lowLimit, int highLimit) {
    //1e5->1  99999->45
    // 9->9 10->1
    //99->18 100->1
    //19->10  20->2对于尾数为9的，下一个的编号为 A-9*nums(9)+1; else A++;
    int box[46]={0};

    //1.get lowLimit box;
    int index=0,temp=lowLimit;
    while(temp!=0){
        index+=temp%10;
        temp/=10;
    }
    ++box[index];
    //2.
    for (int i = lowLimit ; i < highLimit; i++) {
        if (i % 10 == 9) {
            index = index - 9 * sumNext(i);
        }
        ++box[++index];
    }
    int ans=0;
    for(int i=0;i<46;i++){
        ans=std::max(ans,box[i]);
    }
    return ans;
}