//
// Created by skt on 2022/10/4.
//

#include "leetcode921.h"


int leetcode921::minAddToMakeValid(std::string s) {
    //使用栈消除匹配的括号，然后剩余的就是需要添加的个数
//    if(s.size()==0) return 0;
//    std::stack<char> ans;
//    for(char c:s){
//        if(ans.empty()){
//            ans.push(c);
//            continue;
//        }
//        if(c=='('){
//            ans.push(c);
//            continue;
//        }
//        if(c==')' && ans.top()=='('){
//            ans.pop();
//            continue;
//        }else{
//            ans.push(c);
//            continue;
//        }
//    }
//    return ans.size();
    int remain=0,recordL=0;
    for(char c:s){
        if(c=='(') recordL++;
        else{
            if(recordL!=0) recordL--;
            else remain++;
        }
    }
    return recordL+remain;
}