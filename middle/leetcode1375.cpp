//
// Created by skt on 2023/6/14.
//

#include "leetcode1375.h"

// 让所有开着的灯都变成蓝色的时刻的性质是：此时点亮最远的灯的位置恰巧等于点亮灯的个数。
// 若点亮最远的灯的位置大于此时点亮灯的个数，则意味着在点亮最远的灯的位置之前存在着未点亮的灯。

int leetcode1375::numTimesAllBlue(std::vector<int> &flips) {
    int n = flips.size(), maxReach = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        maxReach = std::max(maxReach, flips[i]);
        if(i+1 == maxReach){
            cnt++;
        }
    }
    return cnt;
}
