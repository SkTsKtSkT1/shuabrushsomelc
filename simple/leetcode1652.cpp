//
// Created by skt on 2022/9/24.
//

#include "leetcode1652.h"
#include "iostream"
vector<int> leetcode1652::decrypt(vector<int> &code, int k) {
    int len=code.size();
    vector<int> result(len,0);
    if(k>0){
        for(int i=0;i<len;i++){
            for(int j=0;j<k;j++){
                result[i]+=code[(i+j+1)%len];
            }
        }
    }else if(k<0){
        for(int i=0;i<len;i++){
            for(int j=0;j>k;j--){
                result[i]+=code[(i+j-1+len)%len];
            }
        }
    }
    return result;
}


std::ostream &leetcode1652::operator<<(vector<int> v) {
    for(int & it : v){
        std::cout<<it<<" ";
    }
    std::cout<<std::endl;
}