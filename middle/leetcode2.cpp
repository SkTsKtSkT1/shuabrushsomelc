//
// Created by 25467 on 2023/7/2.
//

#include "leetcode2.h"

ListNode *leetcode2::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carry = 0;
    ListNode* dummyNode = new ListNode(-1);
    ListNode* pre = dummyNode;
    while(l1 != nullptr || l2 != nullptr){
        int x = l1 == nullptr ? 0 : l1 -> val;
        int y = l2 == nullptr ? 0 : l2 -> val;
        int sum = x + y + carry;
        carry = sum / 10;
        sum = sum % 10;
        pre -> next = new ListNode(sum);
        pre = pre -> next;
        if(l1 != nullptr){
            l1 = l1 -> next;
        }
        if(l2 != nullptr){
            l2 = l2 -> next;
        }
    }
    if(carry == 1){
        pre -> next = new ListNode(carry);
    }
    return dummyNode -> next;
}
