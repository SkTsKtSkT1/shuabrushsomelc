//
// Created by lzw on 2022/8/27.
//

#ifndef ALGORITHM_LEETCODE662_H
#define ALGORITHM_LEETCODE662_H

#include "iostream"
#include "queue"


// Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class leetcode662 {
public:
    int widthOfBinaryTree(TreeNode* root);
    int bfs(TreeNode* root);
    int dfs(TreeNode* root);
};

#endif //ALGORITHM_LEETCODE662_H
