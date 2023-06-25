//
// Created by 25467 on 2023/6/25.
//

#include "leetcode1401.h"
#include "functional"

bool leetcode1401::checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
    // f-> 矩形中的点到圆心的最小距离
    std::function<int(int, int, int)> f = [&](int i, int j, int k) -> int {
        if(i <= k && k <= j){
            return 0;
        }
        return k < i ? i - k : k - j;
    };
    int xMin = f(x1, x2, xCenter);
    int yMin = f(y1, y2, yCenter);
    //如果小于，说明存在矩形中的点在圆内
    return xMin * xMin + yMin * yMin <= radius * radius;
}
