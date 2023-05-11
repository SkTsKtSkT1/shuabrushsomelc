//
// Created by 25467 on 2023/5/10.
//

#ifndef ALGORITHM_LEETCODE206_H
#define ALGORITHM_LEETCODE206_H
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class leetcode206 {
public:
    ListNode* reverseList(ListNode* head);
};


#endif //ALGORITHM_LEETCODE206_H
