//
// Created by 25467 on 2023/4/13.
//

#include "leetcode74.h"

bool leetcode74::searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();

    int i=m-1,j=0;
    while(i>=0 && i<m && j>=0 && j<n){
        if(matrix[i][j]==target){
            return true;
        }else if(matrix[i][j]>target){
            i--;
        }else if(matrix[i][j]<target){
            j++;
        }
    }

    return false;
}
