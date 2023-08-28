//
// Created by skt on 2023/8/29.
//

#include "leetcode823.h"
#include "algorithm"
#include "unordered_map"

int leetcode823::numFactoredBinaryTrees(std::vector<int> &arr) {
    int mod = (int) 1e9 + 7, n = arr.size();
    std::sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
        return a < b;
    });
    std::unordered_map<int, long long> uMap;
    for (int i = 0; i < n; ++i) { //对于每一个数字，存储其可能的乘积的个数
        //只把树看成是三个节点，root left right
        //每一步的left都是包含所有可能性的
        int root = arr[i]; //以这个数字作为根节点
        long long cnt = 1L;
        for (int j = 0; j < n; ++j) {
            int cl = arr[j]; //作为子节点
            if (root % cl == 0 && uMap.count(root / cl)) {
                cnt += uMap[cl] * uMap[root / cl];
            }
        }
        uMap[root] = cnt % mod;
    }
    long long res = 0;
    for (const std::pair<const int, const long long> m: uMap) {
        res = (res + m.second) % mod;
    }
    return (int) res;
}
