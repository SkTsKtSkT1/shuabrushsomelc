
//
// Created by lzw on 2022/9/2.
//

#ifndef ALGORITHM_LEETCODE687_H
#define ALGORITHM_LEETCODE687_H
#include "iostream"
/**
 * Definition for a binary tree node.
 *  */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class leetcode687 {
public:
    int maxL;
    int longestUnivaluePath(TreeNode* root);
    int getMaxL(TreeNode* root,int val);
};


#endif //ALGORITHM_LEETCODE687_H
