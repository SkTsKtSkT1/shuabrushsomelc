//
// Created by skt on 2022/10/12.
//

#include "leetcode817.h"
#include "algorithm"
int leetcode817::numComponents(ListNode *head, vector<int> &nums) {
    // if n==1
    if(head->next== nullptr && nums[0]==head->val) return 1;
    else if(head->next== nullptr && nums[0]!=head->val){return 0;}

    int cnt=0;
    while(head->next!= nullptr){
        if(std::find(nums.begin(),nums.end(),head->val)==nums.end()){
            head=head->next;
            //如果最后一个的前一个不是但是最后一个是
            if(head->next==nullptr && std::find(nums.begin(),nums.end(),head->val)!=nums.end()){
                cnt+=1;
            }
        }
        else{
            while(head!=nullptr && std::find(nums.begin(),nums.end(),head->val)!=nums.end()){
                head=head->next;
            }
            cnt+=1;
            //如果尾巴也是在里面
            if(head==nullptr){
                break;
            }

        }
    }
    return cnt;
}


int leetcode817::numComponents1(ListNode *head, vector<int> &nums) {
    //只需要统计有多少个开头即可，也就是false->true
    bool isIn = false;
    int cnt = 0;
    while (head != nullptr) {
        if (std::find(nums.begin(), nums.end(), head->val) != nums.end()) {
            if (!isIn) {
                isIn = true;
                cnt++;
            }
        } else {
            isIn = false;
        }
        head = head->next;
    }
    return cnt;
}

int leetcode817::numComponents2(ListNode *head, vector<int> &nums) {
    std::set<int> s;
    for(int i:nums){
        s.insert(i);
    }
    //只需要统计有多少个开头即可，也就是false->true
    bool isIn = false;
    int cnt = 0;
    while (head != nullptr) {
        if (s.count(head->val)) {
            if (!isIn) {
                isIn = true;
                cnt++;
            }
        } else {
            isIn = false;
        }
        head = head->next;
    }
    return cnt;
}