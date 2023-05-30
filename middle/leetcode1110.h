//
// Created by 25467 on 2023/5/30.
//

#ifndef ALGORITHM_LEETCODE1110_H
#define ALGORITHM_LEETCODE1110_H
#include "../TreeNode.h"
#include "vector"

#include "set"

class leetcode1110 {
public:
    std::vector<TreeNode*> lTree;
    std::set<int> delSet;
    std::vector<TreeNode *> delNodes(TreeNode *root, std::vector<int> &to_delete);
    bool dfs(TreeNode* node, bool f);
};


#endif //ALGORITHM_LEETCODE1110_H
