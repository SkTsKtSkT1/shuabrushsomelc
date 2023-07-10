//
// Created by 25467 on 2023/7/10.
//

#include "leetcode16.h"
#include "algorithm"
int leetcode16::threeSumCloset(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end(), [](int pre, int nxt)->bool{
        return pre < nxt;
    });
    int minDiff = INT_MAX;
    int ans, n = nums.size();
    for(int i = 0; i < n - 2; ++i){
        int x = nums[i];
        if(i > 0 && x == nums[i - 1]) continue; //重复
        int s = x + nums[i + 1] + nums[i + 2];
        if(s > target){
            if(s - target < minDiff){
                ans = s;
            }
            break;
        }

        s = x + nums[n - 2] + nums[n - 1];
        if(s < target){
            if(target - s < minDiff){
                minDiff= target - s;
                ans =s;
            }
            continue;
        }
        int j = i + 1, k = n - 1;
        while(j < k){
            s = x + nums[j] + nums[k];
            if(s == target){
                return target;
            }
            if(s > target){
                if(s - target < minDiff){
                    minDiff = s - target;
                    ans = s;
                }
                k--;
            }else{
                if(target - s < minDiff){
                    minDiff = s - target;
                    ans = s;
                }
                j++;
            }
        }
    }
    return ans;
}
