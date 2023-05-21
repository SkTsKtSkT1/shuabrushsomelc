//
// Created by 25467 on 2023/5/21.
//

#include "leetcode_LCP33.h"
#include "ios"
int leetcode_LCP33::storeWater(std::vector<int> &bucket, std::vector<int> &vat) {
    int n = bucket.size();
    int max_k = 0;
    for(int& v:vat){
        max_k = std::max(max_k, v);
    }
    if(max_k == 0) return 0;
    int ans =INT_MAX;
    for(int k = 1; k <= max_k && k<ans; ++k){ //蓄水次数
        int t = 0; // 升级的次数
        for(int i = 0; i < n; i++){
            t += std::max(0,(vat[i]+k-1)/k-bucket[i]);
        }
        ans = std::min(ans, t + k);
    }
    return ans;
}
