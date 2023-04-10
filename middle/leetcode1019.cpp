//
// Created by 25467 on 2023/4/10.
//

#include "leetcode1019.h"

ListNode *leetcode1019::construct_list(vector<int> &input) {
    ListNode* _dummy_head=new ListNode(-1);
    ListNode* head=_dummy_head;
    for(int& i:input){
        ListNode *temp =new ListNode(i);
        _dummy_head->next=temp;
        _dummy_head=_dummy_head->next;
    }
    head=head->next;
    return head;
}

vector<int> leetcode1019::nextLargerNodes(ListNode *head) {
    vector<int> ans;
    ListNode *cur = head;
    //严格大于！
    while(cur->next!=nullptr){
        ListNode* temp=cur->next;
        if(cur->val < temp->val){
            ans.push_back(temp->val);
            cur=cur->next;
        }else{ //cur->val<=temp->val
            while(temp->next!= nullptr && cur->val >= temp->val){
                temp=temp->next;
            }
            if(temp->next == nullptr && temp->val <= cur->val){
                ans.push_back(0); //if 这个最大或者和尾巴的一样大，则给他单独补0
                cur=cur->next;
            }else{ //找到第一个
                cur=cur->next;
                ans.push_back(temp->val);
            }
        }
    }
    ans.push_back(0);
    return ans;

}


std::ostream &leetcode1019::operator<<(const vector<int> &v) {
    for(vector<int>::const_iterator it = v.begin();it!=v.end();++it){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;

    return std::cout;
}