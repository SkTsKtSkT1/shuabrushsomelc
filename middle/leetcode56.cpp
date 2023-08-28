//
// Created by 25467 on 2023/8/27.
//

#include "leetcode56.h"
#include "algorithm"

std::vector<std::vector<int>> leetcode56::merge(std::vector<std::vector<int>> &intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b)->bool{
        if(a[0] != b[0]){
            return a[0] < b[0];
        }else{
            return a[1] < b[1];
        }
    });
    std::vector<std::vector<int>> res;
    int index = -1;
    for(const std::vector<int>& interval : intervals){
        if(index == -1 || interval[0] > res[index][1]){
            //如果新的起始大于目前的终点，就存储
            res.push_back(interval);
            ++index;
        }else{
            res[index][1] = std::max(res[index][1], interval[1]);
        }
    }
    return res;
}
