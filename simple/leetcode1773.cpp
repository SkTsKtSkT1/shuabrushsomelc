//
// Created by lzw on 2022/10/29.
//

#include "leetcode1773.h"

int leetcode1773::countMatches(vector<vector<string>> &items, std::string ruleKey, std::string ruleValue) {
    int ans=0;
    for(int i=0;i<items.size();i++){
        if(items[i][mt[ruleKey]]==ruleValue) ans++;
    }
    return ans;
}