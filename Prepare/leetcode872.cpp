//
// Created by 25467 on 2023/5/11.
//

#include "leetcode872.h"
#include "string"

bool leetcode872::leafSimilar(TreeNode *root1, TreeNode *root2) {
    std::string s1 = get_leaf(root1, "");
    std::string s2 = get_leaf(root2, "");
    return s1 == s2;

}

std::string leetcode872::get_leaf(TreeNode *node, std::string leaf) {
    if (node == nullptr) return leaf;
    if (node->right == nullptr && node->left == nullptr) {
        leaf = leaf + std::to_string(node->val); //叶子节点
    }

    return get_leaf(node->left, leaf) + get_leaf(node->right, leaf);
}




