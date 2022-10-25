//
// Created by skt on 2022/10/26.
//

#include "leetcode862.h"

int leetcode862::shortestSubarray(vector<int> &nums, int k) {
    //pre 前缀和
    vector<long> preSum(nums.size()+1,0);
    preSum[0]=0;
    for(int i=0;i<nums.size();i++){
        preSum[i+1]=preSum[i]+nums[i];
    }
    //队列
    std::deque<int> q;
    q.push_back(0);
    int ans=INT_MAX;
    for(int i=1;i<=nums.size();i++){
        while(!q.empty() && preSum[i]-preSum[q.front()]>=k){
            ans=std::min(ans,i-q.front());
            q.pop_front();
        }
        while(!q.empty() && preSum[q.back()]>preSum[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    if(ans == INT_MAX) return -1;
    return ans;


}