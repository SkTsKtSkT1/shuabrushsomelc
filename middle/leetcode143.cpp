//
// Created by 25467 on 2023/7/31.
//

#include "leetcode143.h"

ListNode *leetcode143::theMiddle(ListNode *head) {
    ListNode *fast, *slow;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* leetcode143::reverseList(ListNode *head) {
    ListNode *pre = nullptr, *cur = head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

void leetcode143::reorderList(ListNode *head) {
    ListNode *mid = theMiddle(head);
    ListNode* head2 = reverseList(mid);
    while(head2->next){
        ListNode* next = head->next;
        ListNode* next2 = head2->next;
        head->next = head2;
        head2->next = next;
        head = next;
        head2 = next2;
    }
}
