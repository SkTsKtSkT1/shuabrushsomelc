//
// Created by 25467 on 2023/4/13.
//

#include "leetcode678.h"
#include "stack"
using std::stack;
using std::string;

bool leetcode678::checkValidString(std::string s) {
    stack<int> stk_left;
    stack<int> stk_start;
    for (int i=0;i<s.size();++i) {
        if (s[i] == '(') {
            stk_left.push(i);
        } else if (s[i] == '*') {
            stk_start.push(i);
        } else if (s[i] == ')') {
            if (!stk_left.empty()) {
                stk_left.pop();
            } else if (!stk_start.empty()) {
                stk_start.pop();
            } else if (stk_start.empty()) {
                return false;
            }
        }
    }
    //if ( remain
    while(!stk_left.empty() && !stk_start.empty()){
        if(stk_left.top() > stk_start.top()) return false; //如果*在左边 肯定无解
        stk_left.pop();
        stk_start.pop();
    }
    return stk_left.empty(); //因为*可以看作空
}
