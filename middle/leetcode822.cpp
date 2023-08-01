//
// Created by 25467 on 2023/8/2.
//

#include "leetcode822.h"
#include "set"
int leetcode822::flipgame(std::vector<int> &fronts, std::vector<int> &backs) {
    std::set<int> same;
    for(int i = 0; i < fronts.size(); ++i){
        if(fronts[i] == backs[i]){
            same.insert(fronts[i]);
        }
    }
    int ans = INT_MAX;
    for(int i = 0; i < fronts.size(); ++i){
        if(!same.count(fronts[i])){
            ans = std::min(ans, fronts[i]);
        }
        if(!same.count(backs[i])){
            ans = std::min(ans, backs[i]);
        }
    }
    return ans == INT_MAX ? 0 : ans;
}
