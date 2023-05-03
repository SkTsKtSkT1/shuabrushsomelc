//
// Created by 25467 on 2023/5/3.
//

#include "leetcode1003.h"

//对于本题来说，也可以用类似的方法完成：
//字符 a：类似左括号，直接入栈。
//字符 b：如果栈为空，或者栈顶不为 a，则返回 false，否则将栈顶修改为 b（或者出栈再入栈）。
//字符 c：如果栈为空，或者栈顶不为 b，则返回 false，否则弹出栈顶，相当于找到了一个 abc。
//代码实现时， b 和 c 的逻辑可以合并在一起， a 和 b 的入栈逻辑可以合并在一起。

//链接：https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/solution/zhan-jian-ji-xie-fa-pythonjavacgo-by-end-i9o7/


#include "stack"
using std::stack;
bool leetcode1003::isValid(string s) {
    stack<char> stk;
    for(char& c:s){
        if(c=='a') stk.push(c);
        else if(c=='b'){
            if(stk.empty() || stk.top()!='a'){
                return false;
            }else{
                stk.pop();
                stk.push(c);
            }
        }else if(c=='c'){
            if(stk.empty() || stk.top()!='b'){
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}
