//
// Created by lzw on 2022/9/27.
//

#include "mianshi01_02.h"

bool mianshi01_02::checkPremutation(std::string s1, std::string s2) {
    if(s1.size()!=s2.size()) return false;
    std::unordered_map<char,int> nums;
    for(char c:s1){
        nums[c]++;
    }
    for(char c:s2){
        nums[c]--;
    }
    for(std::unordered_map<char,int>::iterator it=nums.begin();it!=nums.end();it++){
        if(it->second!=0){
            return false;
        }
    }
    return true;
}
