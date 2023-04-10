//
// Created by 25467 on 2023/4/10.
//

#ifndef ALGORITHM_LEETCODE_H
#define ALGORITHM_LEETCODE_H

#include "vector"
#include "iostream"
#include "ostream"

using std::vector;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class leetcode1019 {
public:
    vector<int> nextLargerNodes(ListNode* head);
    ListNode* construct_list(vector<int>& input);
    std::ostream &operator<<(const vector<int>& v);
};


#endif //ALGORITHM_LEETCODE_H
