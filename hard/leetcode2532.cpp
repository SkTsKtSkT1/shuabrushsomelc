//
// Created by 25467 on 2023/7/7.
//

#include "leetcode2532.h"
#include "algorithm"
#include "queue"
#include "functional"

int leetcode2532::findCrossingTime(int n, int k, std::vector<std::vector<int>> &time) {
    std::stable_sort(time.begin(), time.end(), [](auto& a, auto& b) -> bool{
        return a[0] + a[2] < b[0] + b[2];
    }); //ensure the relative pos

    std::priority_queue<std::pair<int, int>> waitL, waitR;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> workL, workR;

    for(int i = k - 1; i >= 0; --i){
        waitL.emplace(i, 0);
    }

    int cur = 0;
    while(n){
        while (!workL.empty() && workL.top().first <= cur){
            auto [t, i] =workL.top();
            workL.pop();
            waitL.emplace(i, t);
        }
        while(!workR.empty() && workR.top().first <= cur){
            auto [t, i] = workR.top();
            workR.pop();
            waitR.emplace(i, t);
        }
        if(!waitR.empty()){
            auto [i, t] = waitR.top();
            waitR.pop();
            cur += time[i][2];
            workL.emplace(cur + time[i][3], i);
        }else if(!waitL.empty()){
            auto [i, t] = waitL.top();
            waitL.pop();
            cur += time[i][0];
            workR.emplace(cur + time[i][1], i);
            --n;
        }else if(workL.empty()) cur = workR.top().first;
        else if(workR.empty()) cur = workL.top().first;
        else cur = std::min(workL.top().first, workR.top().first);
    }
    while(!workR.empty()){
        auto [t, i] = workR.top();
        workR.pop();

        cur = std::max(cur, t) + time[i][2];
    }
    return cur;

}
