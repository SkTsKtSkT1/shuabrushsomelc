//
// Created by 25467 on 2023/7/3.
//

#include "leetcode445.h"
#include "stack"

ListNode *leetcode445::addTwoNumbers(ListNode *l1, ListNode *l2) {
    std::stack<int> s1, s2;
    while(l1 != nullptr){
        s1.push(l1->val);
        l1 = l1->next;
    }
    while(l2 != nullptr){
        s2.push(l2->val);
        l2 = l2->next;
    }
    int carry = 0;
    ListNode* dummyHead = new ListNode(-1);
    ListNode* ans = dummyHead;
    while(!s1.empty() || !s2.empty()){
        int x = s1.empty() ? 0 : s1.top();
        int y = s2.empty() ? 0 : s2.top();
        int sum = x + y + carry;
        carry = sum / 10;
        sum %= 10;
        ans -> next = new ListNode(sum);
        ans = ans -> next;
        if(!s1.empty()){
            s1.pop();
        }
        if(!s2.empty()){
            s2.pop();
        }
    }
    if(carry != 0){
        ans -> next = new ListNode(carry);
    }
    return reverseList(dummyHead->next);
}

ListNode *leetcode445::reverseList(ListNode *head) {
    ListNode* pre = nullptr;
    ListNode* cur= head;
    while(cur){
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
