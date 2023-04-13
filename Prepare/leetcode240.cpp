//
// Created by 25467 on 2023/4/13.
//

#include "leetcode240.h"
using std::vector;


bool leetcode240::searchMatrix(std::vector<std::vector<int>> &matrix, int target) {
    int m=matrix.size();
    int n=matrix[0].size();
    int i=m-1,j=0;
    while(i>=0 && i<m && j>=0 && j<n){
        if(matrix[i][j]>target){
            i--; //只要是大那一定是往上走
        }else if(matrix[i][j]<target){
            j++; //这样的话只存在一种情况，一定是往右找，因为如果往下，那么上一次不可能会导致i--
        }else{
            return true;
        }
    }
    return false;
}
