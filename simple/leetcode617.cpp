//
// Created by skt on 2023/8/14.
//

#include "leetcode617.h"

TreeNode *leetcode617::mergeTrees(TreeNode *root1, TreeNode *root2) {
    //前序遍历？ 根 左右
    if(root2 == nullptr){
        return root1;
    }else if(root1 == nullptr){
        return root2;
    }
    root1->val += root2->val;
    root1->left = mergeTrees(root1->left, root2->left);
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;
}
