//
// Created by 25467 on 2023/5/9.
//

#include "leetcode933.h"

int leetcode933::ping(int t) {
    while(!q.empty()){
        int time = q.front();
        if(t - time>3000){
            q.pop();
        }else{
            break;
        }
    }
    q.push(t);

    return q.size();
}
