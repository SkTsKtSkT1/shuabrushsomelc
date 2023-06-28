//
// Created by 25467 on 2023/6/28.
//
//https://leetcode.cn/problems/minimum-incompatibility/solutions/510954/zui-xiao-bu-jian-rong-xing-by-zerotrac2-rwje/
#include "leetcode1681.h"
#include "vector"
#include "iostream"
using std::vector;
int leetcode1681::minimumIncompatibility(std::vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> value(1 << n, -1);
    vector<int> freq(n + 1);
    for (int sub = 0; sub < (1 << n); ++sub) {
        // 判断 sub 是否有 n/k 个 1
        if (__builtin_popcount(sub) == n / k) {
            // 使用数组进行计数
            for (int j = 0; j < n; ++j) {
                if (sub & (1 << j)) {
                    ++freq[nums[j]];
                }
            }
            // 任意一个数不能出现超过 1 次
            bool flag = true;
            for (int j = 1; j <= n; ++j) {
                if (freq[j] > 1) {
                    flag = false;
                    break;
                }
            }
            // 如果满足要求，那么计算 sub 的不兼容性
            if (flag) {
                int lb = INT_MAX, rb = INT_MIN;
                for (int j = 1; j <= n; ++j) {
                    if (freq[j] > 0) {
                        lb = std::min(lb, j);
                        rb = std::max(rb, j);
                    }
                }
                value[sub] = rb - lb;
            }
            // 由于我们使用数组进行计数，因此要将数组恢复原状
            for (int j = 0; j < n; ++j) {
                if (sub & (1 << j)) {
                    --freq[nums[j]];
                }
            }
        }
    }

    vector<int> f(1 << n, -1);
    f[0] = 0;
    for (int mask = 1; mask < (1 << n); ++mask) {
        // 判断 mask 是否有 n/k 倍数个 1
        if (__builtin_popcount(mask) % (n / k) == 0) {
            // 枚举子集
            for (int sub = mask; sub; sub = (sub - 1) & mask) {
                if (value[sub] != -1 && f[mask ^ sub] != -1) {
                    if (f[mask] == -1) {
                        f[mask] = f[mask ^ sub] + value[sub];
                    }
                    else {
                        f[mask] = std::min(f[mask], f[mask ^ sub] + value[sub]);
                    }
                }
            }
        }
    }
    return f[(1 << n) -1];





}
