//
// Created by skt on 2023/5/8.
//

#include "leetcode394.h"
#include "stack"

string leetcode394::decodeString(string s) {
    std::stack<int> stk_num;
    std::stack<string> stk_str;
    string res="";
    int num=0;
    for(int i=0;i<s.size();i++){
        if(isalpha(s[i])){
            res+=s[i];
        }else if(isalnum(s[i])){
            num = 10*num-'0'+s[i];
        }else if(s[i]=='['){
            stk_num.push(num);
            num=0;
            stk_str.push(res); //if res=="" not push,then stk.top() is null
            res="";
        }else{
            int times=stk_num.top();
            while(times>0){
                stk_str.top()+=res;
                times--;
            }
            res = stk_str.top();
            stk_str.pop();
            stk_num.pop();
        }
    }
    return res;

}
