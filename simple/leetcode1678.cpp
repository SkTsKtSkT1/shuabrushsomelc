//
// Created by skt on 2022/11/6.
//

#include "leetcode1678.h"

string leetcode1678::interpret(std::string command) {
    string ans;
    for(int i=0;i<command.size();){
        if(command[i]=='G'){
            ans+='G';
            i++;
        }else if(command[i]=='('){
            if(command[i+1]==')'){
                ans+='o';
                i+=2;
            }else{
                ans+="al";
                i+=4;
            }
        }
    }
    return ans;
}