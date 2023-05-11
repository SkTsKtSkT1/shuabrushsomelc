//
// Created by 25467 on 2023/5/10.
//

#include "leetcode206.h"

ListNode *leetcode206::reverseList(ListNode *head) {
    if(head == nullptr) return head;

    ListNode* pre = nullptr;
    ListNode* cur = head;

    while(cur!= nullptr){
        ListNode* temp = cur ->next;
        cur->next = pre;
        pre=cur;
        cur= temp;
    }

    return pre;
}
