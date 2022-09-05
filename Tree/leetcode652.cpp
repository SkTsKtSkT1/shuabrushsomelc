//
// Created by lzw on 2022/9/5.
//

#include "leetcode652.h"

std::vector<TreeNode *> leetcode652::findDuplicateSubtress(TreeNode *root) {
    dfs(root);
    return result;
}

std::string leetcode652::dfs(TreeNode *node) {
    //通过深度优先，将每个根节点的信息用string保存，使用hashmap进行存储，若有两个相同的，即为题解。
    if(node== nullptr) return "";
    std::string nodeString= std::to_string(node->val)+" "+ dfs(node->left)+" "+dfs(node->right);
    treeMap[nodeString]++;
    if(treeMap[nodeString]==2)  result.push_back(node);
    return nodeString;
}

