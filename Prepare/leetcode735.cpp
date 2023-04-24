//
// Created by 25467 on 2023/4/24.
//

#include <algorithm>
#include "leetcode735.h"
#include "stack"
//绝对值表示行星的大小，正负表示行星的移动方向（正表示向右移动，负表示向左移动）。每一颗行星以相同的速度移动。
vector<int> leetcode735::asteroidCollision(vector<int> &asteroids) {
    std::stack<int> stk;
    for(int i=0;i<asteroids.size();++i){
        bool alive=true;
        while(alive && asteroids[i]<0 && !stk.empty() && stk.top()>0){
            alive=stk.top()<-asteroids[i];
            if(stk.top()<=-asteroids[i]){
                stk.pop();
            }
        }
        if(alive){
            stk.push(asteroids[i]);
        }
    }
    vector<int> res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }
    std::reverse(res.begin(), res.end());
    return res;
}
