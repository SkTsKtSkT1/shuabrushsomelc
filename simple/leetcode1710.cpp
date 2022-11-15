//
// Created by lzw on 2022/11/15.
//

#include "leetcode1710.h"
#include "algorithm"
int leetcode1710::maximumUnits(vector<vector<int>> &boxTypes, int truckSize) {
    sort(boxTypes.begin(),boxTypes.end(),[&](const vector<int>& a,const vector<int>& b)->bool {
        return a[1]>b[1];
    });
    int ans=0;
    for(const vector<int>& box:boxTypes){
        if(truckSize<box[0]) {
            ans+=truckSize*box[1];
            break;
        }
        truckSize-=box[0];
        ans+=box[0]*box[1];
    }

    return ans;
}