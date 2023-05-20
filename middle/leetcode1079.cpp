//
// Created by 25467 on 2023/5/19.
//

#include "leetcode1079.h"
#include "unordered_map"
#include "cstring"
#include "numeric"
using std::unordered_map;
using std::string;
using std::vector;

const int MX = 8;
int c[MX][MX];

int init = []() {
    for (int i = 0; i < MX; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // 预处理组合数
    }
    return 0;
}();

int leetcode1079::numTilePossibilities(std::string tiles) {
    unordered_map<char, int> counts;
    for (char c: tiles) counts[c]++; // 统计每个字母的出现次数
    int f[tiles.size() + 1];
    memset(f, 0, sizeof(f));
    f[0] = 1; // 构造空序列的方案数
    int n = 0;
    for (auto &[_, cnt]: counts) { // 枚举第 i 种字母
        n += cnt; // 常数优化：相比从 tiles.length() 开始要更快
        for (int j = n; j; j--) // 枚举序列长度 j
            // 枚举第 i 种字母选了 k 个，注意 k=0 时的方案数已经在 f[j] 中了
            for (int k = 1; k <= j && k <= cnt; k++)
                f[j] += f[j - k] * c[j][k];
    }
    return std::accumulate(f + 1, f + n + 1, 0);
}
