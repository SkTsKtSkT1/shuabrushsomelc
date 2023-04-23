//
// Created by skt on 2023/4/22.
//

#include "leetcode724.h"

int leetcode724::pivotIndex(vector<int> &nums) {
    vector<int> prefix(nums.size()+1,0);
    for(int i=1;i<prefix.size();++i){
        prefix[i]=prefix[i-1]+nums[i-1];
    }
    //as for j, left:prefix[j-1] right:prefix[prefix.size()-1]-prefix[j];
    for(int i=0;i<nums.size();++i){
        if(prefix[i+1]==prefix[prefix.size()-1]-prefix[i+1]+nums[i]){
            return i;
        }
    }
    return -1;
}
