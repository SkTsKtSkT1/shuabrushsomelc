//
// Created by lzw on 2022/10/30.
//

#include "leetcode784.h"

vector<string> leetcode784::letterCasePermutation(std::string s) {
    dealEach(_ans,s,0);
    return _ans;
}

void leetcode784::dealEach(vector<std::string> &ans,std::string &s, int index) {
    if(index==s.size()){
        ans.push_back(s);
        return ;
    }
    if(!std::isalpha(s[index])){
        dealEach(ans,s,index+1);
    }else{
        s[index]= char(std::tolower(s[index]));
        dealEach(ans,s,index+1);
        s[index]= char(std::toupper(s[index]));
        dealEach(ans,s,index+1);
    }
}