//
// Created by 25467 on 2023/5/20.
//

#include "leetcode1373.h"
//https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/solution/hou-xu-bian-li-pythonjavacgo-by-endlessc-gll3/
int leetcode1373::maxSumBST(TreeNode *root) {
    dfs(root);
    return ans;
}
