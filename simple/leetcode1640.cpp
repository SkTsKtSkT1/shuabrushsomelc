//
// Created by lzw on 2022/9/22.
//

#include "leetcode1640.h"

bool leetcode1640::canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    int n=pieces.size();
    //按照索引顺序排序
    std::sort(pieces.begin(), pieces.end(),[&](vector<int>& a,vector<int>& b)->bool{
        //return std::find(arr.begin(),arr.end(),a[0])-arr.begin()<std::find(arr.begin(),arr.end(),b[0])-arr.begin();
        return std::find(arr.begin(),arr.end(),a[0])<std::find(arr.begin(),arr.end(),b[0]);
    });
    int index=0; //arr的index
    //开始遍历
    for(int i=0;i<n;i++){
        if(arr[index]!=pieces[i][0])
            return false;
        for(int j=0;j<pieces[i].size();j++){
            if(pieces[i][j]!=arr[index]){
                return false;
            }
            index++;
        }
    }
    return true;
}