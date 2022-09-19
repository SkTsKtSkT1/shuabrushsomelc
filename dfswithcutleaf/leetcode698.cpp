//
// Created by skt on 2022/9/20.
//

#include "leetcode698.h"


bool leetcode698::canPartitionKSubsets(vector<int> &nums, int k) {
    if(nums.size()<k) return false;
    int numSum=std::accumulate(nums.begin(),nums.end(),0);
    if(numSum%k) return false; //如果和起来不整除k
    int target=numSum/k;
    int maxNum= *std::max_element(nums.begin(),nums.end());
    if(maxNum>target) return false;
    std::sort(nums.begin(),nums.end());
    vector<int> used(nums.size(),0);
    return dfs(nums,used,k,0,target,0);

}

bool leetcode698::dfs(vector<int> &nums,vector<int>& used,int k,int sum,int& target,int index) {
    if(k==0) return true;//划分完毕
    if(sum==target) return dfs(nums,used,k-1,0,target,0); //该次划分符合目标值,则继续后k-1组的划分
    for(int i=index;i<nums.size();i++){
        if(used[i]) continue;
        else if(sum+nums[i]>target) continue;
        sum+=nums[i];
        used[i]=1;
        if(dfs(nums,used,k,sum,target,i+1)) return true; //
        used[i]=0;
        sum-=nums[i];
    }
    return false;
}