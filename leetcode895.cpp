//
// Created by lzw on 2022/11/30.
//

#include "leetcode895.h"

//https://leetcode.cn/problems/maximum-frequency-stack/solution/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-oich/
FreqStack::FreqStack() {

}


void FreqStack::push(int val) {
    if(numMap[val]==stacks.size()){
        //stack.size()->最大的出现频率
        //stacks.emplace_back();
        stacks.push_back({});
    }
    stacks[numMap[val]].push(val);
    ++numMap[val];
}

int FreqStack::pop() {
    int val=stacks.back().top();
    stacks.back().pop();
    if(stacks.back().empty()){
        stacks.pop_back();
    }
    --numMap[val];
    return val;
}


