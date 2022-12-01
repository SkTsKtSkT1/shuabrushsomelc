//
// Created by lzw on 2022/12/1.
//

#include "leetcode1779.h"
#include "math.h"
int leetcode1779::nearestValidPoint(int x, int y, vector<vector<int>> &points) {
    auto f=[&](vector<int> point)->int{
        return abs(x-point[0])+abs(y-point[1]);
    };

    int minDis=INT_MAX;
    int index=-1;

    for(int i=0;i<points.size();i++){
        if(x==points[i][0] || y==points[i][1]) {
            int tempDis = f(points[i]);
            if (tempDis < minDis) {
                minDis = tempDis;
                index = i;
            }
        }
    }


    return index;
}


