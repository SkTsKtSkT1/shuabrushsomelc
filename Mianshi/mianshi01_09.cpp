//
// Created by skt on 2022/9/29.
//

#include "mianshi01_09.h"

bool mianshi01_09::isFlipedString(std::string s1, std::string s2) {
    if(s1.size()!=s2.size()) return false;
    string string22=s2+s2;
    //if string22 包含s1 则return true 否则return false；
    //具体是如何实现find（）函数，即string22中是否包含s1 (leetcode28：实现Strstr（）

    return string22.find(s1)!=string::npos;
//    string string11=s1+s1;
//    int index=0;
//    int lastIndex=2*s1.size();
//
//    for(int i=0;i<lastIndex;i++){
//        if(string11[i]==s2[0]){ //存在问题，即重复出现某一串
//            index=i;
//            lastIndex=i+s1.size();
//            break;
//        }
//    }
//
//    for(int i=index;i<lastIndex;i++){
//        //if(string11[i]!=s2[i-index]){
//        if(s1[i%s1.size()]!=s2[i-index]){
//            return false;
//        }
//    }
//    return true;
}