//
// Created by lzw on 2022/11/29.
//

#include "leetcode1758.h"
#include "algorithm"
int leetcode1758::minOperations(string s) {
    //change to 0101... or 10101.... 的次数记为x和y  则x+y=n
    //for example 0101...
    int cnt=0;
    char example[2]={'0','1'};
    for(int i=0;i<s.size();i++){
        if(s[i]!=example[i%2]){
            cnt++;
        }
    }
    return std::min(cnt,int(s.size()-cnt));
}
