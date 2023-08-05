//
// Created by skt on 2023/8/6.
//

#include "leetcode24.h"

ListNode *leetcode24::swapPairs(ListNode *head) {
    if(head == nullptr) return head;
    ListNode* dummyHead = new ListNode(-1, head);
    ListNode *pre = dummyHead, *cur = head, *next = head->next;
    while(cur != nullptr && next != nullptr){
        ListNode* nnext = next->next;
        pre->next = next;
        next->next = cur;
        cur->next = nnext;

        pre = cur;
        cur = nnext;
        if(nnext == nullptr){
            break;
        }
        next = nnext->next;
    }
    return dummyHead->next;
}
