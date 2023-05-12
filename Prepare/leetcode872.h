//
// Created by 25467 on 2023/5/11.
//

#ifndef ALGORITHM_LEETCODE872_H
#define ALGORITHM_LEETCODE872_H
#include "string"
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class leetcode872 {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2);
    std::string get_leaf(TreeNode* node, std::string leaf);

};


#endif //ALGORITHM_LEETCODE872_H
