//
// Created by 25467 on 2023/8/28.
//

#include "leetcode57.h"

std::vector<std::vector<int>>
leetcode57::insert(std::vector<std::vector<int>> &intervals, std::vector<int> &newInterval) {
    int idx = 0;
    std::vector<std::vector<int>> res;
    while(idx < intervals.size() && intervals[idx][1] < newInterval[0]){
        res.push_back(intervals[idx]);
        ++idx;
    }
    //------
    //    ------
    //        ------
    while(idx < intervals.size() && intervals[idx][0] <= newInterval[1]){ //能融合的区间一定是要在一块的，如果idx的起始大于新区间的开头，那么就跳出
        newInterval[0] = std::min(newInterval[0], intervals[idx][0]);
        newInterval[1] = std::max(newInterval[1], intervals[idx][1]);
        ++idx;
    }
    res.push_back(newInterval);
    while(idx < intervals.size()){
        res.push_back(intervals[idx]);
        ++idx;
    }
    return res;
}
