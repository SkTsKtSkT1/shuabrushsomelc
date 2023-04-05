//
// Created by 25467 on 2023/4/5.
//

#include "leetcode1578.h"

int leetcode1578::minCost(std::string colors, vector<int> &neededTime) {
    int res = 0;

    for(int i = 1; i < neededTime.size(); ++i){
        if(colors[i] == colors[i-1]){
            if(neededTime[i] > neededTime[i-1]){
                res += neededTime[i-1];
            }else{
                res += neededTime[i];
                neededTime[i] = neededTime[i-1];
            }
        }
    }

    return res;

}
