//
// Created by lzw on 2022/11/5.
//

#include "leetcode1106.h"

bool leetcode1106::parseBoolExpr(std::string expression) {
    std:: stack<char> operation;
    std::stack<int> s;
    for(int i=0;i<expression.size();i++){
        if(expression[i]=='t'||expression[i]=='f'){
            s.push(expression[i]=='f'?0:1);
        }else if(expression[i]=='('){
            s.push(-1);
        }else if(expression[i]=='&' || expression[i]=='|' || expression[i]=='!'){
            operation.push(expression[i]);
        }else if(expression[i]==')') {//遇到右括号 开始计算
            if(!operation.empty()) {
                char opera = operation.top();
                operation.pop();
                if(!s.empty()){
                    int temp=s.top();
                    s.pop();
                    if(opera=='!'){
                        temp=abs(temp-1); //0->1 1->0
                    }else if(opera=='|'){
                        while(!s.empty() && s.top()!=-1){
                            temp|=s.top();
                            s.pop();
                        }
                    }else if(opera=='&'){
                        while(!s.empty() && s.top()!=-1){
                            temp &= s.top();
                            s.pop();
                        }
                    }
                    s.pop(); //pop ( -1
                    s.push(temp);
                }
            }
        }


    }
    return s.top();

}

