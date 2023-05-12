//
// Created by 25467 on 2023/5/11.
//

#ifndef ALGORITHM_LEETCODE1372_H
#define ALGORITHM_LEETCODE1372_H

#include "../TreeNode.h"

class leetcode1372 {
public:
    int ans=0;
    int longestZigZag(TreeNode* root);
    int get_length(TreeNode* node, bool isLeft);
};



#endif //ALGORITHM_LEETCODE1372_H
