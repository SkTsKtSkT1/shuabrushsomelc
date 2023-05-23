//
// Created by 25467 on 2023/5/23.
//

#include "leetcode1090.h"
#include "algorithm"
#include "unordered_map"

using std::vector;
int leetcode1090::largestValsFromLabels(std::vector<int> &values, std::vector<int> &labels, int numWanted, int useLimit) {
    int n = values.size(), res = 0, k = 0;
    vector<std::pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        v.emplace_back(values[i], labels[i]);
    }
    std::sort(v.begin(), v.end(), [&](std::pair<int, int> a, std::pair<int, int> b) -> bool {
        return a.first > b.first;
    });//v order from big to small;
    std::unordered_map<int, int> u_map;
    for (int i = 0; i < n && k < numWanted; ++i) {
        auto &[x, y] = v[i];
        if (u_map[y] < useLimit) {
            res += x;
            k++;
            u_map[y]++;
        }
    }
    return res;
}
