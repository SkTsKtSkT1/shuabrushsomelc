//
// Created by 25467 on 2023/4/9.
//

#include "leetcode2399.h"
#include "unordered_map"

bool leetcode2399::checkDistances(std::string s, vector<int> &distance) {
    std::unordered_map<char, int> uMap;//store the desired index should be occurred;
    for(int i=0; i<s.size();i++){
        if(!uMap.count(s[i])){
            uMap[s[i]]=i+distance[s[i]-'a']+1;
        }else{
            if(i!=uMap[s[i]]){ // 定义是刚好等于distance[i]!
                return false;
            }
        }
    }
    return true;
}