//
// Created by 25467 on 2023/4/19.
//

#include "leetcode238.h"

vector<int> leetcode238::productExceptSelf(vector<int> &nums) {
    vector<int> ans(nums.size(),1);
    int left=1,right=1;
    for(int i=0;i<nums.size();++i){
        ans[i]*=left;
        left*=nums[i];

        ans[nums.size()-1-i]*=right;
        right*=nums[nums.size()-i-1];

    }
    return ans;
}
