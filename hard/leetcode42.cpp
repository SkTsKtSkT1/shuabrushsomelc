//
// Created by 25467 on 2023/7/23.
//

#include "leetcode42.h"

int leetcode42::trap(std::vector<int> &height) {
//    int n = height.size();
//    std::vector<int> preMax(n, 0), sufMax(n, 0);
//    preMax[0] = height[0];
//    sufMax[n - 1] = height[n - 1];
//    for(int i = 1; i < n; ++i){
//        preMax[i] = std::max(preMax[i - 1], height[i]);
//        sufMax[n - 1 - i] = std::max(sufMax[n - i], height[n - 1 - i]);
//    }
//
//    int ans = 0;
//    for(int i = 0; i < n; ++i){
//        ans += std::min(preMax[i], sufMax[i]) - height[i];
//    }
//    return ans;
    int n = height.size();
    int l = 0, r = n - 1;
    int ans = 0;
    int preMax = 0, sufMax = 0;
    while(l <= r){ //if l == r cal l==r的容量
        preMax = std::max(preMax, height[l]);
        sufMax = std::max(sufMax, height[r]);
        if(preMax < sufMax){
            ans += preMax - height[l];
            ++l;
        }else{
            ans += sufMax - height[r];
            --r;
        }
    }
    return ans;
}
