//
// Created by skt on 2022/10/3.
//

#include "leetcode1784.h"

bool leetcode1784::checkOnesSegment(std::string s) {
//    int cnt=0;
//    int index=0;
//    while(index<s.size()){
//        if(s[index]=='1'&&s[index+1]!='1'){
//            cnt++;
//        }
//        index++;
//    }
    //其实意思也是说字符串结构为11111。。。11100000000
    int cnt=0;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]){
            cnt++;
        }
        if(cnt>1){
            return false;
        }
    }
    return true;
}