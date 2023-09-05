//
// Created by skt on 2023/9/6.
//

#include "leetcode1123.h"
#include <functional>
#include <algorithm>

TreeNode *leetcode1123::lcaDeepestLeaves(TreeNode *root) {
    //深度，最近的祖先节点
    //得到深度之后判断，如果左子树更深，那么考虑左子树，如果右子树更深，考虑右子树
    //否则返回当前节点
    //如果一样深，说明祖先节点一定是当前节点，如果某一边深，说明当前更深的一边存在答案，那么这个节点可能就是答案
    std::function<std::pair<int, TreeNode *>(TreeNode *)> dfs =
            [&](TreeNode *node) -> std::pair<int, TreeNode *> {
                if (node == nullptr) return std::make_pair(0, nullptr);
                std::pair<int, TreeNode *> v1 = dfs(node->left);
                std::pair<int, TreeNode *> v2 = dfs(node->right);
                int lvl = std::max(v1.first, v2.first) + 1;
                if (v1.first > v2.first) return std::make_pair(lvl, v1.second);
                if (v1.first < v2.first) return std::make_pair(lvl, v2.second);
                return std::make_pair(lvl, node);
    };
    return dfs(root).second;

}
