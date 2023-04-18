//
// Created by 25467 on 2023/4/18.
//

#ifndef ALGORITHM_LEETCODE1026_H
#define ALGORITHM_LEETCODE1026_H

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//就一个节点来说所谓最大差值，就是祖先的最大值或者最小值和自己的val的差值。
//只需要知道所有祖先可能的最大值和最小值，在遍历时携带传递即可。
class leetcode1026 {
public:
    int maxAncestorDiff(TreeNode* root);
    int maxAncestorDiff(TreeNode* root, int max, int min);
};


#endif //ALGORITHM_LEETCODE1026_H
