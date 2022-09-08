//
// Created by skt on 2022/9/9.
//

#include "leetcode1598.h"

int leetcode1598::getOperations(std::string &operation) {
    if(operation=="./"){
        return 0;
    }
    if(operation=="../"){
        return -1;
    }
    return 1;
}

int leetcode1598::minOperations(vector<std::string> &logs) {
    int ans=0;
    for(int i=0;i<logs.size();i++){
        ans+= getOperations(logs[i]);
        if(ans>0) ans=0;
    }
    return ans;
}