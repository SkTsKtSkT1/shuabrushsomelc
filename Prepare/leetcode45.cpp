//
// Created by 25467 on 2023/4/25.
//

#include "leetcode45.h"

int leetcode45::jump(vector<int> &nums) {
    if (nums.size() == 1) return 0;
    int reach = 0;// 当前覆盖最远距离下标
    int next_reach = nums[0];  // 下一步覆盖最远距离下标
    int step = 0;
    for (int i = 0; i < nums.size(); i++) {
        next_reach = std::max(i + nums[i], next_reach);
        if (next_reach >= nums.size() - 1) return (step + 1);
        if (i == reach) {
            step++;
            reach = next_reach;
        }
    }
    return step;
}


