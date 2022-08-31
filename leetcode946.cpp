//
// Created by lzw on 2022/8/31.
//

#include "leetcode946.h"

bool leetcode946::validateStackSequences(std::vector<int> &pushed, std::vector<int> &popped) {
    std::stack<int> stack;
    int len=pushed.size();
    int popIndex=0;
    for(int i=0;i<len;i++){
        stack.push(pushed[i]);
        //如果调换会导致segment error 先非空然后取top；
        while( !stack.empty()&&stack.top()==popped[popIndex] ){
            stack.pop();
            popIndex++;
        }
    }
    return stack.empty();
}
