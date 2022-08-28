//
// Created by lzw on 2022/8/27.
//

#include "leetcode662.h"
//维护一个记录节点索引的数组，最后right-left+1即最大宽度；
int leetcode662::widthOfBinaryTree(TreeNode* root) {
    return bfs(root);
}

//bfs 遍历一层，将这一层节点的左右节点加入
int leetcode662::bfs(TreeNode* root){
    if(root== nullptr) return 0;
    std::queue<std::pair<TreeNode*, unsigned int>> q;  //(node,index)
    unsigned int result =0;
    q.push(std::make_pair(root,0ULL));
    unsigned   left=0;
    unsigned  right=0;
    while(q.size()>0){
        int curLen=q.size();
        left=q.front().second;
        for(int i=0;i<curLen;i++){
            TreeNode* x=q.front().first;
            unsigned index=q.front().second;
            right=std::max(right,index);
            if(x->left){
                q.push(std::make_pair(x->left,index*2-left));
            }
            if(x->right){
                q.push(std::make_pair(x->right,index*2+1-left));//因为测试案例112溢出，所以将index化为每一层从1开始编号。
            }
            q.pop();
        }
        result=std::max(result,right-left+1);
    }
    return result;
}


//dfs
int leetcode662::dfs(TreeNode* root){
    typedef unsigned long long ULL;
    int max=0;//
    return 0;

}