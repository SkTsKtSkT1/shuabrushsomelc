//
// Created by 25467 on 2023/4/25.
//

#include "leetcode101.h"

bool leetcode101::isSymmetric(TreeNode *root) {
    if(root== nullptr) return true;
    return is_child_sym(root->left,root->right);
}



bool leetcode101::is_child_sym(TreeNode *left, TreeNode *right) {
    if(left== nullptr && right== nullptr) return true;
    if(left== nullptr||right== nullptr || left->val!=right->val) return false;
    return is_child_sym(left->right,right->left)&& is_child_sym(left->left,right->right);
}
