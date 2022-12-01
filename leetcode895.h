//
// Created by lzw on 2022/11/30.
//

#ifndef ALGORITHM_LEETCODE895_H
#define ALGORITHM_LEETCODE895_H
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
#include "unordered_map"
#include "vector"
#include "stack"
class FreqStack {
public:
    FreqStack();

    void push(int val) ;

    int pop();

    std::unordered_map<int,int> numMap; //记录数字出现的次数 key:num val:times
    std::vector<std::stack<int>> stacks;//按频次分为多个栈
};


#endif //ALGORITHM_LEETCODE895_H
