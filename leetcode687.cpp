//
// Created by lzw on 2022/9/2.
//

#include "leetcode687.h"


//对于一棵树，最长路径包含的情况：
//1.该节点与其左or右子节点相等
//2.该节点与其根节点相等


int leetcode687::longestUnivaluePath(TreeNode *root) {
    if(root==nullptr) return 0;
    return getMaxL(root,root->val);
}

int leetcode687::getMaxL(TreeNode *root,int val) {
    if(root== nullptr) return 0;
    int leftLen=getMaxL(root->left,root->val);
    int rightLen=getMaxL(root->right,root->val);
    maxL=std::max(maxL,leftLen+rightLen);//why?? 路径长度可以是左右子树和根节点构成
    if(root->val==val) return std::max(rightLen,leftLen)+1;//计算如果值相等，左右字数能提供的最大路径长度2
    return 0;
}