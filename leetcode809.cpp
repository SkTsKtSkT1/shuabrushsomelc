//
// Created by lzw on 2022/11/25.
//

#include "leetcode809.h"

int leetcode809::expressiveWords(std::string s, vector<std::string> &words) {
    int ans=0;
    for(const string& word:words){
        ans+=check(s,word);
    }
    return ans;
}

//双指针
int leetcode809::check(const std::string &s, const std::string &word) {
    int ps=0,pw=0;
    while(ps<s.size() && pw<word.size()){
        if(s[ps]!=word[pw]){
            return 0;
        }

        char cs=s[ps];
        int cnts=0;
        while(ps<s.size() && s[ps]==cs){
            ++ps;
            ++cnts;
        }

        int cntw=0;
        while(pw<word.size() && word[pw]==cs){
            ++pw;
            cntw++;
        }

        if(cntw>cnts) return 0;
        if(cnts>cntw && cnts<3) return 0;
    }
    //必须都处理完 否则不行
    return ps==s.size() && pw==word.size();
}