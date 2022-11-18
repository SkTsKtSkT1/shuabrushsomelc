//
// Created by lzw on 2022/11/18.
//

#include "leetcode891.h"
#include "algorithm"
#include "math.h"
//首先我们将 nums 数组排序。选取一个最小值 nums[i]，和一个最大值 nums[j]。满足最小值为 nums[i] 且最大值为 nums[j] 的子序列有 2^(j - i - 1) 个。
//考虑nums[i]可以作为最大值也可以作为最小值，那么作为最大值，考虑左边，作为最小值 考虑右边，则nums[i]的贡献为两者相加，即2^(i)*nums[i]-2^(n-i-1)*nums[i];
int leetcode891::sumSubseqWidths(vector<int> &nums) {
    sort(nums.begin(),nums.end(),[&](int a,int b)->bool {return a<b;});
    int mod=int(1e9+7);
    long res=0;
    long coef=1;
    for(int i=0;i<nums.size();i++){
        res=(res+(nums[i]-nums[nums.size()-i-1])*coef)%mod;
        coef=(coef<<1)%mod;
    }
    return res;
}

