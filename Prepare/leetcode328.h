//
// Created by 25467 on 2023/5/9.
//

#ifndef ALGORITHM_LEETCODE328_H
#define ALGORITHM_LEETCODE328_H

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class leetcode328 {
public:
    ListNode* oddEvenList(ListNode* head);
};


#endif //ALGORITHM_LEETCODE328_H
