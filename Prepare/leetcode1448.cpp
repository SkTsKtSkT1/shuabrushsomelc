//
// Created by 25467 on 2023/5/11.
//

#include "leetcode1448.h"
#include "cmath"
#include "iostream"
//一棵树的好节点数目，等于左右子树的好节点数目之和，如果根节点是好节点，那么再加1 。 递归的过程中，不断更新max即可。
int leetcode1448::goodNodes(TreeNode *root) {
    count_node(root, INT_MIN);
    return ans;
}

void leetcode1448::count_node(TreeNode *node, int max) {
    if(node == nullptr) return;
    if(node->val>=max){
        max = node->val;
        ans++;
    }
    count_node(node->left,max);
    count_node(node->right,max);
}

