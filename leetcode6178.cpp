//
// Created by lzw on 2022/9/11.
//

#include "leetcode6178.h"


int leetcode6178::minGroups(vector<vector<int>> &intervals) {
    //按每个的区间左侧从小到大排列
//    std::sort(intervals.begin(),intervals.end(),[&](vector<int> a,vector<int> b){
//        if(a[0]!=b[0]) return a[0]<b[0];
//        return a[1]<b[1];
//    });
    std::sort(intervals.begin(), intervals.end());
    priority_queue<int,vector<int>,std::greater<>> pq;
    for(vector<int> cur:intervals){
        int left=cur[0],right=cur[1];
        if(pq.empty()) pq.push(right);
        else{
            if(left<=pq.top())  pq.push(right);
            else{
                pq.pop();
                pq.push(right);
            }
        }
    }
    return pq.size();


}