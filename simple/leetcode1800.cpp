//
// Created by skt on 2022/10/7.
//

#include "leetcode1800.h"

int leetcode1800::maxAscendingSum(vector<int> &nums) {
    int s = 0, r = 0, ans = 0;
    for(int x: nums) {
        if(x > r) ans = std::max(ans, s += x);
        else s = x;
        r = x;
    }
    return ans;
}
