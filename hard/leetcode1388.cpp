//
// Created by skt on 2023/8/18.
//

#include "leetcode1388.h"
#include <cstring>

int leetcode1388::maxSizeSlices(std::vector<int> &slices) {
    return std::max(maxSizeSlice(slices, 0, slices.size() - 2),
                    maxSizeSlice(slices, 1, slices.size() - 1));
}

int leetcode1388::maxSizeSlice(std::vector<int> &slice, int start, int end) {
    //求从start到end之间的不相邻的n/3个数字的最大和
    // len = end - start + 1 and len = 3*n - 1 ->n = m + 1 / 3；
    int len = end - start + 1, k = (len + 1) / 3;
    int dp[len + 1][k + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= len; ++i){
        int size = slice[start + i - 1];
        for(int j = 1; j <= k; ++j){
            int preSize = i > 1 ? dp[i - 2][j - 1] : 0;
            dp[i][j] =std::max(preSize + size, dp[i - 1][j]);
        }
    }
    return dp[len][k];
}
