//
// Created by 25467 on 2023/8/20.
//

#include "leetcode2236.h"

bool leetcode2236::checkTree(TreeNode *root) {
    //return root->val == root->left->val + root->right->val;
    //强化版本
    if(root->left == nullptr && root->right == nullptr) return true;
    return root->val == root->left->val + root->right->val
        && checkTree(root->left) && checkTree(root->right);
}
