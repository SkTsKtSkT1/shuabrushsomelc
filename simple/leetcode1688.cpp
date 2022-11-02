//
// Created by skt on 2022/11/3.
//

#include "leetcode1688.h"

int leetcode1688::maxRepeating(std::string sequence, std::string word) {
    int m=word.size(),n=sequence.size();
    if(m>n) return 0;
    vector<int> f(n,0);
    //每一个位置作为结束位置，判断前面的若干个字符是否恰好是字符串
    for(int i=m-1;i<n;i++){ //从m-1 因为i=1。。。m-2没有意义
        bool valid=true;
        for(int j=0;j<m;j++){
            if(sequence[i-m+1+j]!=word[j]){
                valid=false;
                break;
            }
        }
        if(valid){
            f[i]=(i==m-1?0:f[i-m])+1;
        }
    }
    return *std::max_element(f.begin(), f.end());

}