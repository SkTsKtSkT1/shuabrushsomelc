//
// Created by 25467 on 2023/4/12.
//

#include "leetcode1147.h"

int leetcode1147::longestDecomposition(string text) {
    int n=text.size();
    //从后往前找一个与字符串首字母相同的字母
    for(int i=n-1;i>=0;--i){
        if(text[i]==text[0] && text.substr(i)==text.substr(0,n-i)) {//i~n 0~n-i
            if(2*i>n){ //还没到中间就找到了一个
                return 2+ longestDecomposition(text.substr(n-i,2*i-n));
            }else if(2*i==n){
                return 2;
            }else{
                return 1;
            }
        }
    }
    return 1;
}
