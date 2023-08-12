//
// Created by skt on 2023/8/12.
//

#include "leetcode23.h"
#include "functional"
#include "queue"

ListNode *leetcode23::mergeKLists(std::vector<ListNode *> &lists) {
    auto cmp = [](const ListNode* a, const ListNode* b){
        return a->val > b->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq(cmp);
    for(auto head : lists){
        if(head){
            pq.push(head);
        }
    }
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while(!pq.empty()){
        ListNode* node = pq.top();
        pq.pop();
        if(node->next){
            pq.push(node->next);
        }
        cur->next = node;
        cur = cur->next;
    }
    return dummy->next;
}
