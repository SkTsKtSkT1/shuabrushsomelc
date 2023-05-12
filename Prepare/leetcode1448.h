//
// Created by 25467 on 2023/5/11.
//

#ifndef ALGORITHM_LEETCODE1448_H
#define ALGORITHM_LEETCODE1448_H
#include "../TreeNode.h"

class leetcode1448 {
public:
    int ans=0;
    int goodNodes(TreeNode* root);
    void count_node(TreeNode* node,int max);
};


#endif //ALGORITHM_LEETCODE1448_H
