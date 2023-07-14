//
// Created by 25467 on 2023/7/14.
//

#include "leetcode979.h"
#include "functional"
int leetcode979::distributeCoins(TreeNode *root) {
    int ans = 0;
    std::function<int(TreeNode*)> dfs = [&](TreeNode* root) -> int {
        if(!root) return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans += std::abs(l + r + root->val - 1);
        return l + r + root->val - 1;
    };
    dfs(root);
    return ans;
}
