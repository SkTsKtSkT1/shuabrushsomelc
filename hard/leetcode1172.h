//
// Created by skt on 2023/4/28.
//

#ifndef ALGORITHM_LEETCODE1172_H
#define ALGORITHM_LEETCODE1172_H
#include "vector"
#include "stack"
#include "functional"
#include "queue"
using std::vector;
using std::stack;
using std::priority_queue;

class leetcode1172 {
public:
    int capacity; // 栈的容量
    vector<stack<int>> stacks; // 所有栈
    priority_queue<int, vector<int>, std::greater<>> idx; // 未满栈的下标
    leetcode1172(int capacity):capacity(capacity){};

    void push(int val) ;
    int pop() ;
    int popAtStack(int index);
};


#endif //ALGORITHM_LEETCODE1172_H
