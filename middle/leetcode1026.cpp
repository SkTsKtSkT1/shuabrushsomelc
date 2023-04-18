//
// Created by 25467 on 2023/4/18.
//

#include "leetcode1026.h"
//就一个节点来说所谓最大差值，就是祖先的最大值或者最小值和自己的val的差值。
//只需要知道所有祖先可能的最大值和最小值，在遍历时携带传递即可。
int leetcode1026::maxAncestorDiff(TreeNode *root) {
    return maxAncestorDiff(root,root->val,root->val);
}


int leetcode1026::maxAncestorDiff(TreeNode* root, int max, int min) {
    if(root == nullptr) return 0;
    if(root->val>max){
        max=root->val;
    }else if(root->val<min){
        min=root->val;
    }
    if(root->left== nullptr && root->right== nullptr){
        return max-min;
    }
    int left=0;
    int right=0;
    if(root->left!= nullptr){
        left= maxAncestorDiff(root->left,max,min);
    }
    if(root->right!= nullptr){
        right= maxAncestorDiff(root->right,max,min);
    }
    return left>right?left:right;
}

