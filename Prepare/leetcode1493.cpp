//
// Created by skt on 2023/4/22.
//

#include "leetcode1493.h"

int leetcode1493::longestSubarray(vector<int> &nums) {
    int l=0;
    int ans=0;
    int cnt=1;
    for(int r=0;r<nums.size();++r){
        if(nums[r]==0){
            cnt--;
        }
        while(l<=r && cnt<0){
            if(nums[l++]==0) cnt++;
        }
        ans=std::max(ans,r-l+1);
    }
    //r-l+1 contains the 0, but it should be delete!
    return ans-1;
}
