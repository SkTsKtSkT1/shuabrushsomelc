//
// Created by 25467 on 2023/5/11.
//

#include "leetcode1372.h"
#include "algorithm"
int leetcode1372::longestZigZag(TreeNode *root) {

    return 0;
}

int leetcode1372::get_length(TreeNode *node, bool isLeft) { //bool means 子节点怎么从父节点而来
    if(node == nullptr){
        return 0;
    }
    int r=get_length(node->right,false);
    int l= get_length(node->left,true);

    //renew the answer
    ans = std::max<int>({ans,r,l});

    if(isLeft){
        return r+1;
    }else{
        return l+1;
    }
}
