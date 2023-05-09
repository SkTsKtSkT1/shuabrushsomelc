//
// Created by 25467 on 2023/5/9.
//

#ifndef ALGORITHM_LEETCODE2095_H
#define ALGORITHM_LEETCODE2095_H

 struct ListNode {
     int val;
     ListNode *next;

     ListNode() : val(0), next(nullptr) {}

     ListNode(int x) : val(x), next(nullptr) {}

     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class leetcode2095 {
public:
    ListNode* deleteMiddle(ListNode* head);
};


#endif //ALGORITHM_LEETCODE2095_H
