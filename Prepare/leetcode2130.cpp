//
// Created by 25467 on 2023/5/10.
//

#include "leetcode2130.h"
#include "stack"
//fast 控制使前一半元素入栈 后一半的时候出栈并做比较大小
int leetcode2130::pairSum(ListNode *head) {
    ListNode* fast=head ,*slow=head;
    std::stack<ListNode*> s;
    int ans=0;
    while(slow!= nullptr){
        if(fast!=nullptr){
            s.push(slow);
        }else{
            ans = std::max(s.top()->val+slow->val,ans);
            s.pop();
        }
        slow = slow ->next;
        if(fast!= nullptr){
            fast= fast->next->next;
        }

    }
    return ans;
}
