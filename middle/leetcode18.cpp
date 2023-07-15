//
// Created by 25467 on 2023/7/15.
//

#include "leetcode18.h"
#include "algorithm"
std::vector<std::vector<int>> leetcode18::fourSum(std::vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end(), [](int pre, int nxt) -> bool{
       return pre < nxt;
    });
    int n = nums.size();
    std::vector<std::vector<int>> res;

    for(int i = 0; i < n; ++i){
        if(i != 0 && nums[i] == nums[i - 1]){
            continue;
        }
        for(int j = i + 1; j < n; ++j){
            if(j != i + 1 && nums[j] == nums[j - 1]){
                continue;
            }
            int p = j + 1, q = n - 1;
            long long tar_pq = (long long) target - nums[i] - nums[j];
            while(p < q){
                if(nums[p] + nums[q] == tar_pq){
                    res.push_back({nums[i], nums[j], nums[p], nums[q]});
                    do{
                        ++p;
                    }while(p < n && nums[p] == nums[p - 1]);
                }else if(nums[p] + nums[q] < tar_pq){
                    ++p;
                }else{
                    --q;
                }
            }
        }
    }

    return res;
}
