//
// Created by 25467 on 2023/5/28.
//

#include "leetcode1439.h"
#include "vector"
using std::vector;

int leetcode1439::kthSmallest(std::vector<std::vector<int>> &mat, int k) {
    int sl = 0, sr = 0;
    for (auto &row: mat) {
        sl += row[0];
        sr += row.back();
    }
    // 二分模板 https://www.bilibili.com/video/BV1AP41137w7/
    int left = sl - 1, right = sr; // 开区间 (sl-1,sr)
    while (left + 1 < right) { // 开区间不为空
        // 循环不变量：
        // f(left) < k
        // f(right) >= k
        int mid = left + (right - left) / 2;
        int left_k = k;
        if (dfs(mat, left_k, mat.size() - 1, mid - sl)) // 先把第一列的所有数都选上
            right = mid; // 二分范围缩小至开区间 (left, mid)
        else // f(mid) < k
            left = mid; // 二分范围缩小至开区间 (mid, right)
    }
    return right;
}

bool leetcode1439::dfs(vector<vector<int>> &mat, int &left_k, int i, int s) {
    if (i < 0) // 能递归到这里，说明数组和不超过二分的 mid
        return --left_k == 0; // 是否找到 k 个
    for (int x: mat[i]) { // 「枚举选哪个」，注意 mat[i] 是有序的
        if (x - mat[i][0] > s) // 选 x 不选 mat[i][0]
            break; // 剪枝：后面的元素更大，无需枚举
        if (dfs(mat, left_k, i - 1, s - (x - mat[i][0]))) // 选 x 不选 mat[i][0]
            return true; // 找到 k 个就一直返回 true，不再递归
    }
    return false;
}


//链接：https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/solution/san-chong-suan-fa-bao-li-er-fen-da-an-du-k1vd/

