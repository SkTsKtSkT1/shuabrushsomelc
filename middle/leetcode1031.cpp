//
// Created by 25467 on 2023/4/26.
//

#include "leetcode1031.h"
#include "functional"
//使用前缀和维护分割点两边的定长子数组最大和即可。https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/solution/tu-jie-mei-you-si-lu-yi-zhang-tu-miao-do-3lli/

int leetcode1031::maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
    int res=0;
    vector<int> prefix(nums.size()+1,0);
    for(int i=1;i<=nums.size();++i){
        prefix[i]=prefix[i-1]+nums[i-1];
    }

    std::function<void(int,int)> f=[&](int firstLen,int secondLen)->void{
        int max_sum_A=0;
        for(int i=firstLen+secondLen;i<=nums.size();i++){
            max_sum_A = std::max(max_sum_A,prefix[i-secondLen]-prefix[i- secondLen-firstLen]);
            res = std::max(res,max_sum_A+prefix[i]-prefix[i-secondLen]);
        }
    };
    f(firstLen,secondLen);
    f(secondLen,firstLen);
    return res;
}
