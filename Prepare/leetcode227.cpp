//
// Created by 25467 on 2023/4/12.
//

#include "leetcode227.h"
#include "stack"
////整数除法仅保留整数部分。
////你可以假设给定的表达式总是有效的。所有中间结果将在 [-231, 231 - 1] 的范围内。
////*、 then +-

int leetcode227::calculate(std::string s) {
    int res=0;
    int d=0;
    char sign = '+';
    std::stack<int> nums;
    for(int i=0; i< s.size(); ++i){
        if(s[i] > '0'){ // +-*/ <'0'
            d=d*10 -'0'+s[i];
        }
        if((s[i]<'0' && s[i]!= ' ')|| i== s.size()-1){
            if(sign=='+'){
                nums.push(d);
            }else if(sign == '-'){
                nums.push(-d);
            }else if( sign == '*' || sign == '/'){
                int temp= sign=='*'?temp*nums.top():nums.top()/d;
                nums.pop();
                nums.push(temp);
            }
            sign=s[i];
            d=0;
        }
    }
    while(!nums.empty()){
        res+=nums.top();
        nums.pop();
    }
    return res;
}
