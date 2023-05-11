//
// Created by 25467 on 2023/5/9.
//

#include "leetcode328.h"
//结点1作为奇数链的头 结点2作为偶数链的头
//
//从第3个点开始遍历，依次轮流附在奇、偶链的后面
//
//遍历完后，奇数链的尾连向偶链的头，偶链的尾为空， 返回奇数链的头
ListNode *leetcode328::oddEvenList(ListNode *head) {
    if(head == nullptr) return head;

    ListNode* odd_head = head;
    ListNode* even_head = head->next;

    ListNode* p1=odd_head, *p2=even_head;
    while(p2!=nullptr && p2->next!= nullptr){
        p1->next = p1->next->next;
        p2->next = p2->next->next;
        p1=p1->next;
        p2=p2->next;
    }
    p1->next = even_head;

    return odd_head;
}
