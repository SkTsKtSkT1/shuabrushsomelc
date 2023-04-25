//
// Created by 25467 on 2023/4/25.
//

#ifndef ALGORITHM_LEETCODE101_H
#define ALGORITHM_LEETCODE101_H


 // Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;

     TreeNode() : val(0), left(nullptr), right(nullptr) {}

     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 //
class leetcode101 {
public:
    bool isSymmetric(TreeNode* root);
    bool is_child_sym(TreeNode* left,TreeNode* right);
};


#endif //ALGORITHM_LEETCODE101_H
