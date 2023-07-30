//
// Created by 25467 on 2023/7/30.
//

#include "leetcode142.h"

ListNode *leetcode142::detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;
    //fast 2 steps, slow 1 step
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){   // slow : x + y     fast : x + y + k ( y + z ) -> k(y+z) = x + y -> x = (k - 1) (y + z) + z;
            //也即是说，如果我们定义一个答案指针 ansansans 指向链表头部，然后 ansansans 和慢指针一起向前走，那么它们一定会在环入口相遇。
            ListNode* ans = head;
            while(ans != slow){
                ans = ans->next;
                slow = slow->next;
            }
            return ans;
        }
    }


    return nullptr;


}
