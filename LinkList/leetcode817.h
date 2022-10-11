//
// Created by skt on 2022/10/12.
//

#ifndef ALGORITHM_LEETCODE817_H
#define ALGORITHM_LEETCODE817_H
#include "vector"
#include "set"
using std::vector;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class leetcode817 {
public:
    int numComponents(ListNode* head, vector<int>& nums);
    int numComponents1(ListNode* head, vector<int>& nums);
    int numComponents2(ListNode* head, vector<int>& nums);
};

#endif //ALGORITHM_LEETCODE817_H
