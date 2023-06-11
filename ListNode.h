//
// Created by 25467 on 2023/6/11.
//

#ifndef ALGORITHM_LISTNODE_H
#define ALGORITHM_LISTNODE_H


struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif //ALGORITHM_LISTNODE_H
