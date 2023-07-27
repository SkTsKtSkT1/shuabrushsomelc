//
// Created by skt on 2023/7/26.
//

#include "leetcode2569.h"
#include "numeric"
#include "iostream"
std::vector<long long>
leetcode2569::handleQuery(std::vector<int> &nums1, std::vector<int> &nums2, std::vector<std::vector<int>> &queries) {
//    int l = queries[0][1], r = queries[0][2], p = queries[1][1];
//    long long res = std::accumulate(nums2.begin(), nums2.end(), 0ll);
//    //as for l -> r  count 1 and 0 times as m and n
//    //then res = res + p * m;
//    int cnt = 0;
//    //query 1
//    for(int i = 0; i < nums1.size(); ++i){
//        if(i <= r && i >= l){
//            nums1[i] = !nums1[i];
//        }
//        if(nums1[i] == 1){
//            ++cnt;
//            //query 2
//            nums2[i] += p;
//        }
//    }
//    res += p * cnt;
//    return std::vector<long long>{res};
    int n = nums1.size();
    build(nums1, 1, 1, n);
    std::vector<long long> ans;
    long long sum = accumulate(nums2.begin(), nums2.end(), 0LL);
    for (auto &q : queries) {
        if (q[0] == 1) update(1, 1, n, q[1] + 1, q[2] + 1);
        else if (q[0] == 2) sum += 1LL * q[1] * cnt1[1];
        else ans.push_back(sum);
    }
    return ans;

//https://leetcode.cn/problems/handling-sum-queries-after-update/solutions/2119436/xian-duan-shu-by-endlesscheng-vx80/


}
