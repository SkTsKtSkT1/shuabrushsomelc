//
// Created by lzw on 2022/9/5.
//

#ifndef ALGORITHM_LEETCODE652_H
#define ALGORITHM_LEETCODE652_H

#include "vector"
#include "iostream"
#include "unordered_map"

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class leetcode652 {
private:
    std::vector<TreeNode*> result;
    std::unordered_map<std::string,int> treeMap;
public:
    std::vector<TreeNode*> findDuplicateSubtress(TreeNode* root);
    std::string dfs(TreeNode* node);
};


#endif //ALGORITHM_LEETCODE652_H
