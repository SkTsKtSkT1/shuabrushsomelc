//
// Created by 25467 on 2023/7/29.
//

#include "leetcode141.h"

bool leetcode141::hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    //fast 2 steps, slow 1 step
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) return true;
    }
    return false;
}
