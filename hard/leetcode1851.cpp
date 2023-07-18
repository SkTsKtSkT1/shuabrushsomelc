//
// Created by 25467 on 2023/7/18.
//

#include "leetcode1851.h"
#include "algorithm"
#include "numeric"
#include "functional"

std::vector<int> leetcode1851::minInterval(std::vector<std::vector<int>> &intervals, std::vector<int> &queries) {
    // 按照区间长度从小到大排序
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> pre, const std::vector<int> nxt) -> bool{
        return pre[1] - pre[0] < nxt[1] - nxt[0];
    });

    // 离线：按查询位置排序
    int m = queries.size();
    std::vector<int> ids(m);
    std::iota(ids.begin(), ids.end(), 0);
    std::sort(ids.begin(), ids.end(), [queries](int i, int j) -> bool{
       return queries[i] < queries[j];
    });

    // 并查集
    std::vector<int> fa(m + 1);
    iota(fa.begin(), fa.end(), 0);
    std::function<int(int)> find = [&](int x) -> int {
        return x == fa[x] ? x : fa[x] = find(fa[x]);
    };

    // 对于每个区间，回答 [left, right] 内的询问
    std::vector<int> ans(m, -1);
    for(const auto& p : intervals){
        int left = p[0];
        int right = p[1];
        int len = right - left + 1;
        auto pos = std::lower_bound(ids.begin(), ids.end(), left, [&](int id, int value) -> bool{
            return queries[id] < value;
        }) - ids.begin();
        for(int i = find(pos); i < m && queries[ids[i]] <= right; i = find(i + 1)){
            ans[ids[i]] = len;
            fa[i] = i + 1;
        }
    }

    return ans;


}
