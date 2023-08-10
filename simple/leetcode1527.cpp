//
// Created by skt on 2023/8/11.
//

#include "leetcode1527.h"

int leetcode1527::diagonalSum(std::vector<std::vector<int>> &mat) {
    size_t n = mat.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == n - i - 1) {
            ans += mat[i][i];
        } else {
            ans += mat[i][n - i - 1];
            ans += mat[i][i];
        }
    }
    return ans;
}
