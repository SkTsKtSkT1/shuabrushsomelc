//
// Created by 25467 on 2023/6/23.
//

#include "leetcode2496.h"

int leetcode2496::maximumValue(std::vector<std::string> &strs) {
    int ans = 0;
    for(std::string& str : strs){
        ans = std::max(ans, cntVal(str));
    }
    return ans;
}

int leetcode2496::cntVal(std::string &str) {
    int ans = 0;
    for(char& c : str){
        if(isalpha(c)){
            return str.size();
        }else{
            ans = ans * 10 + c - '0';
        }
    }
    return ans;
}
