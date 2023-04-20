//
// Created by 25467 on 2023/4/20.
//

#include "leetcode1187.h"
#include "algorithm"
#include "functional"
//定义 f(i) 为使数组 arr1 的前 i+1 项（下标0∼i）递增，且 保留
//arr1[i] 的情况下的最小替换次数。
//https://leetcode.cn/problems/make-array-strictly-increasing/solution/yi-wei-dp-si-lu-xiang-jie-cpy3-by-newhar/
int leetcode1187::makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    std::sort(arr2.begin(), arr2.end(),[&](int a,int b)->bool{
        return a<b; //升序排列
    });
    arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
    arr1.push_back( max_v + 5); // 右侧哨兵 inf
    arr1.insert(arr1.begin(), -1); // 左侧哨兵 -1

    vector<int> dp(arr1.size(),  max_v);
    dp[0] = 0;
    for(int i = 1; i < arr1.size(); ++i) {
        int j = lower_bound(arr2.begin(),arr2.end(), arr1[i]) - arr2.begin();
        for(int k = 1; k <= std::min(i-1,j); ++k){ // 1. 枚举替换的个数 k = 1 to min(i-1,j)
            if(arr1[i-k-1] < arr2[j-k]) {
                dp[i] = std::min(dp[i], dp[i-k-1] + k);
            }
        }
        if(arr1[i-1] < arr1[i]) { // 2. 不替换 arr1[i-1]
            dp[i] = std::min(dp[i], dp[i-1]);
        }
    }

    int res = dp[arr1.size()-1];
    return (res >=  max_v)? -1 : res;

}
