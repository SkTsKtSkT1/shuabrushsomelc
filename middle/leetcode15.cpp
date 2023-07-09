//
// Created by 25467 on 2023/7/9.
//

#include "leetcode15.h"
#include "algorithm"
std::vector<std::vector<int>> leetcode15::threeSum(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), [](int pre, int nxt)->bool{
        return pre < nxt;
    });
    std::vector<std::vector<int>> ans;
    int n = nums.size();
    for(int i = 0; i < n - 2; ++i){
        int x = nums[i];
        if(i && x == nums[i - 1]) continue; //重复
        if(x + nums[i + 1] + nums[i + 2] > 0) break; //设 s = nums[first] + nums[first+1] + nums[first+2]，如果 s > 0，由于数组已经排序，后面无论怎么选，选出的三个数的和不会比 s 还小，所以只要 s > 0 就可以直接 break 外层循环了。
        if(x + nums[n - 2] + nums[n - 1] < 0) continue; //如果 nums[first] + nums[n-2] + nums[n-1] < 0，由于数组已经排序，nums[first] 加上后面任意两个数都是小于 0 的，所以下面的双指针就不需要跑了。但是后面可能有更大的 nums[first]，所以还需要继续枚举，continue 外层循环。
        int j = i + 1, k = n - 1;
        while(j < k){
            int s = x + nums[j] + nums[k];
            if(s > 0){
                --k;
            }else if(s < 0){
                ++j;
            }else{
                ans.push_back({x, nums[j], nums[k]});
                for(++j; j < k && nums[j] == nums[j - 1]; ++j);
                for(--k; k > j && nums[k] == nums[k + 1]; --k);
            }
        }
    }
    return ans;
}
