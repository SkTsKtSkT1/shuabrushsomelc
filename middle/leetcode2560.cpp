//
// Created by 25467 on 2023/9/19.
//

#include "leetcode2560.h"
#include <algorithm>
//https://leetcode.cn/problems/house-robber-iv/?envType=daily-question&envId=2023-09-19
int leetcode2560::minCapability(std::vector<int> &nums, int k) {
    int left = 0, right = *max_element(nums.begin(), nums.end());
    while(left + 1 < right){
        int mid = left + (right - left) / 2;
        if(check(nums, k, mid)){
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

bool leetcode2560::check(std::vector<int> &nums, int k, int mx) {
    int cnt = 0, n = nums.size();
    for(int i = 0; i < n; ++i){
        if(nums[i] <= mx){
            cnt++;
            i++;
        }
    }
    return cnt >= k;
}
