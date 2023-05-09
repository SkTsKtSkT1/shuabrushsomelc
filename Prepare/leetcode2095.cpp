//
// Created by 25467 on 2023/5/9.
//

#include "leetcode2095.h"

ListNode *leetcode2095::deleteMiddle(ListNode *head) {
    if(head->next == nullptr) return nullptr;
    int cnt=1;
    ListNode* temp=head;
    while(temp->next!= nullptr){
        cnt++;
        temp = temp->next;
    }
    int del_num=cnt/2;
    temp = head;
    while(del_num-1>0){
        temp = temp->next;
        del_num--;
    }
    ListNode* c=temp->next;
    temp->next = temp->next->next;
    delete c;
    return head;
}
