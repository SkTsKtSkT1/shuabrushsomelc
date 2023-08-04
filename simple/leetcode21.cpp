//
// Created by 25467 on 2023/8/5.
//

#include "leetcode21.h"

ListNode *leetcode21::mergeTwoLists(ListNode *list1, ListNode *list2) {
    ListNode* dummyHead = new ListNode(-1);
    ListNode* tmp = dummyHead;
    while(list1 != nullptr && list2 != nullptr){
        if(list1->val > list2->val){
            tmp->next = list2;
            list2 = list2->next;
        }else{
            tmp->next = list1;
            list1 = list1->next;
        }
        tmp = tmp->next;
    }
    tmp->next = (list1 == nullptr ? list2 : list1);
    return dummyHead->next;

}
