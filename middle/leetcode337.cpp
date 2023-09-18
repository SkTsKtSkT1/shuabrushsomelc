//
// Created by 25467 on 2023/9/18.
//

#include "leetcode337.h"
#include <functional>

int leetcode337::rob(TreeNode *root) {
    //rob not_rob
    std::function<std::pair<int, int>(TreeNode*)> dfs = [&](TreeNode* node) -> std::pair<int, int>{
        if(node == nullptr){
            return std::make_pair(0, 0);
        }
        std::pair<int, int> left = dfs(node->left);
        std::pair<int, int> right = dfs(node->right);

        int rob = left.second + right.second + node->val;
        int not_rob = std::max(left.first, left.second) + std::max(right.first, right.second);
        return std::make_pair(rob, not_rob);
    };
    std::pair<int, int> res = dfs(root);
    return std::max(res.first, res.second);
}
