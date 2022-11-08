//
// Created by lzw on 2022/11/8.
//

#include "leetcode1684.h"
#include "set"
int leetcode1684::countConsistentStrings(string allowed, vector<string> &words) {
    //use set to contain
    std::set<char> allowedSet;
    int ans=0;
    for(char c:allowed){
        allowedSet.insert(c);
    }
    for(string word:words){
        bool flag= true;
        for(char c:word){
            if(allowedSet.count(c)){
                continue;
            }else{
                flag= false;
                break;
            }
        }
        if(flag){
            ans++;
        }
    }
    return ans;
}


int leetcode1684::countConsistentStrings1(string allowed, vector<string> &words) {
    //use s26-bit to contain
    int ans=0;
    int mask=0;
    for(char c:allowed){
        mask|=1<<(c-'a');
    }
    for(const string& word:words){
        int mask1=0;
        for(auto c:word){
            mask1|=1<<(c-'a');
        }
        if((mask1|mask)==mask){
            ans++;
        }
    }
    return ans;
}