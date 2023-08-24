//
// Created by skt on 2023/8/25.
//

#include "leetcode1448.h"
#include <functional>
int leetcode1448_Twice::goodNodes(TreeNode *root) {
    int res = 0;
    std::function<void(TreeNode*, int)> dfs = [&res, &dfs](TreeNode* node, int max_val) -> void{
        if(node == nullptr){
            return;
        }
        if(node->val >= max_val){
            res += 1;
            max_val = node->val;
        }
        dfs(node->left, max_val);
        dfs(node->right, max_val);
        return;
    };
    dfs(root, 0);
    return res;
}
