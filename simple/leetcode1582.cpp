//
// Created by Administrator on 2022/9/4.
//

#include "leetcode1582.h"

int leetcode1582::numSpecial(std::vector<std::vector<int>>& mat){
    int rows=mat.size();
    int cols=mat[0].size();
    int ans=0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(mat[i][j]==1 && isSpecial(mat,i,j)){
                ans++;
            }
        }
    }
    return ans;
}

bool leetcode1582::isSpecial(std::vector<std::vector<int>> &mat, int i, int j){
    int rows=mat.size();
    int cols=mat[0].size();
    for(int row=0;row<rows;row++){
        if(row!=i && mat[row][j]==1){
            return false;
        }
    }
    for(int col=0;col<cols;col++){
        if(col!=j && mat[i][col]==1){
            return  false;
        }
    }
    return true;
}