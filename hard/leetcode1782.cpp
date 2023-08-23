//
// Created by skt on 2023/8/23.
//

#include "leetcode1782.h"
#include "algorithm"
#include <unordered_map>
//ref: https://leetcode.cn/problems/count-pairs-of-nodes/solutions/2400682/ji-bai-100cong-shuang-zhi-zhen-dao-zhong-yhze/
std::vector<int> leetcode1782::countPairs(int n, std::vector<std::vector<int>> &edges, std::vector<int> &queries) {
    std::vector<int> deg(n + 1, 0);
    std::unordered_map<int, int> cnt_e;
    for(const std::vector<int>& edge : edges){
        int x = edge[0], y = edge[1];
        if(x > y) std::swap(x, y);
        deg[x] += 1;
        deg[y] += 1;
        cnt_e[x << 16 | y] += 1;
    }
    std::vector<int> ans(queries.size());
    std::vector<int> sortedDeg = deg;
    std::sort(sortedDeg.begin(), sortedDeg.end(), [](int a, int b)->bool{
        return a < b;
    }); // from small to big

    for(int j = 0; j < queries.size(); ++j){
        //题目要求(a,b) a < b，对于这里可以通过调换位置保证满足
        int q = queries[j];
        int left = 1, right = n;
        while(left < right){
            if(sortedDeg[left] + sortedDeg[right] <= q){
                left += 1;
            }else{
                ans[j] += right - left;
                right -= 1;
            }
        }
        for(auto& [k, v] : cnt_e){
            int s = deg[k >> 16] + deg[k & 0xffff]; //出现的总边数，包含重复的
            if(s > q && s - v <= q){ //如果大于q但是减去重复的小于q 说明加上了不应该有的
                ans[j] -= 1;
            }
        }
    }
    return ans;
}
