//
// Created by skt on 2023/9/7.
//

#include "leetcode2594.h"
#include <numeric>
#include <algorithm>
#include <cmath>
long long leetcode2594::repairCars(std::vector<int> &ranks, int cars) {
    long long curTime = *std::min_element(ranks.begin(), ranks.end()) * (cars * cars);
    long long left = 0, right = curTime;
    //(left , right)
    while(right > left + 1){
        long long mid = left + (right - left) / 2;
        if(carNum(ranks, mid) >= cars){ //大于等于都要收缩，因为要找到最小的边界
            right = mid;
        }else{
            left = mid;
        }
    }
    return right;
}

long long leetcode2594::carNum(std::vector<int> &ranks, long long time) {
    // t = r * n ^2 -> n = sqrt(t /r )
    long long total = 0;
    for(int rank : ranks){
        total += std::sqrt(time / rank);
    }
    return total;
}
