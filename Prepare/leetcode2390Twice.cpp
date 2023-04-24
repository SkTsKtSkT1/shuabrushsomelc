//
// Created by 25467 on 2023/4/24.
//

#include "leetcode2390Twice.h"

string leetcode2390Twice::removeStars(string s) {
    string ans;
    for(int i=0;i<s.size();++i){
        if(s[i]!='*'){
            ans+=s[i++];
        }else{
            ans.pop_back();
        }
    }
    return ans;
}
