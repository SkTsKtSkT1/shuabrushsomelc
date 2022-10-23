//
// Created by lzw on 2022/10/23.
//

#include "leetcode1768.h"

//string leetcode1768::mergeAlternately(std::string word1, std::string word2) {
//    string ans;
//    if(word1.size()==word2.size()){
//        for(int i=0;i<word1.size();i++){
//            ans.push_back(word1[i]);
//            ans.push_back(word2[i]);
//        }
//        return  ans;
//    }
//    if(word1.size()>word2.size()){
//        for(int i=0;i<word2.size();i++){
//            ans.push_back(word1[i]);
//            ans.push_back(word2[i]);
//        }
//        ans+=string(word1.begin()+word2.size(),word1.end());
//    }
//    if(word2.size()>word1.size()){
//        for(int i=0;i<word1.size();i++){
//            ans.push_back(word1[i]);
//            ans.push_back(word2[i]);
//        }
//        ans+=string(word2.begin()+word1.size(),word2.end());
//    }
//    return ans;
//}

string leetcode1768::mergeAlternately(std::string word1, std::string word2) {
    int w1=0,w2=0;
    string ans;
    ans.reserve(word1.size()+word2.size());
    while(w1<word1.size()||w2<word2.size()){
        if(w1<word1.size()){
            ans+=word1[w1];
            w1++;
        }
        if(w2<word2.size()){
            ans+=word2[w2];
            w2++;
        }
    }
    return ans;
}