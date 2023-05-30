//
// Created by 25467 on 2023/5/30.
//

#include "leetcode1110.h"

using std::vector;
std::vector<TreeNode *> leetcode1110::delNodes(TreeNode *root, std::vector<int> &to_delete) {
    //把 toDelete 全部丢到一个哈希表 s 中，这样可以 O(1) 判断节点值是否在 toDelete 中。
    for(int& i:to_delete){
        delSet.insert(i);
    }
    dfs(root, true);
    return lTree;
}

//f -> 这个节点是否为潜在的新的根节点
bool leetcode1110::dfs(TreeNode *node, bool f) {
    if(node == nullptr) return false;
    bool _f = delSet.count(node->val);
    // push进结果的逻辑是, 当前节点不在删除数据里面, 且是潜在的新的根节点, 其余结果不做考虑.
    if(f && !_f){
        lTree.push_back(node);
    }
    //这两个结果为真，表示子节点需要被删除，也就是说当前作为父节点的node左右都指向空，
    //如果当前父节点要被删除，那么继续遍历左右子节点
    if(dfs(node->left, _f) && !_f) node->left = nullptr;
    if(dfs(node->right, _f) && !_f) node->right = nullptr;
    return _f;
}


