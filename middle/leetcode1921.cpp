//
// Created by 25467 on 2023/9/4.
//

#include "leetcode1921.h"
#include "algorithm"

int leetcode1921::eliminateMaximum(std::vector<int> &dist, std::vector<int> &speed) {
    //恰 在某一分钟开始时到达城市，这会被视为 输掉 游戏
    //计算怪物需要的步数
    std::vector<int> steps(dist.size());
    for(int i = 0; i < dist.size(); ++i){
        steps[i] = (dist[i] % speed[i] == 0 ? dist[i] / speed[i] : dist[i] / speed[i] + 1);
    }
    std::sort(steps.begin(), steps.end());
    for(int i = 0; i < steps.size(); ++i){
        if(steps[i] < i + 1){
            return i;
        }
    }
    return steps.size();
}
