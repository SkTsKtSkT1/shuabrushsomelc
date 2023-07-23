//
// Created by skt on 2023/7/24.
//

#include "leetcode771.h"
#include "set"
int leetcode771::numJewelsInStones(std::string jewels, std::string stones) {
    std::set<char> jewel;
    for(char& j : jewels){
        jewel.insert(j);
    }
    int ans = 0;
    for(char& s : stones){
        if(jewel.count(s)){
            ++ans;
        }
    }
    return ans;
}
