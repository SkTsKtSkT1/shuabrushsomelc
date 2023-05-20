//
// Created by 25467 on 2023/5/20.
//

#ifndef ALGORITHM_LEETCODE1373_H
#define ALGORITHM_LEETCODE1373_H
#include "../TreeNode.h"
#include "iostream"
#include "tuple"
class leetcode1373 {
private:
    int ans=0;
    std::tuple<int, int, int> dfs(TreeNode* node){
        if(node == nullptr){
            return {INT_MAX, INT_MIN, 0};
        }
        auto [l_min, l_max, l_sum] = dfs(node->left);
        auto [r_min, r_max, r_sum] = dfs(node->right);
        int x = node->val;
        if( x<= l_max || x>= r_min){
            return {INT_MIN, INT_MAX, 0};
        }
        int s= l_sum + r_sum + x;
        ans = std::max(ans, s);
        return {std::min(l_min, x), std::max(r_max, x), s};
    }
public:
    int maxSumBST(TreeNode* root) ;
};


#endif //ALGORITHM_LEETCODE1373_H
