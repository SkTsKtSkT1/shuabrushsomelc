//
// Created by 25467 on 2023/6/11.
//

#include "leetcode1171.h"
#include "map"
ListNode *leetcode1171::removeZeroSumSublists(ListNode *head) {
    std::map<int, ListNode*> m; //index && the node
    ListNode* dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* tmp = dummyHead;
    int sum = 0;
    while(tmp!= nullptr){
        sum += tmp->val;
        m[sum] = tmp;
        tmp = tmp->next;
    }
    tmp = dummyHead;
    sum = 0;
    while(tmp != nullptr){
        sum += tmp->val;
        if(m.count(sum)){
            tmp->next = m[sum]->next;
        }
        tmp = tmp->next;
    }
    return dummyHead->next;
}
