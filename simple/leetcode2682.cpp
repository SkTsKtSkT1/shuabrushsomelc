//
// Created by 25467 on 2023/8/16.
//

#include "leetcode2682.h"
#include <cstring>

std::vector<int> leetcode2682::circularGameLosers(int n, int k) {
    if(n == 1){
        return std::vector<int>();
    }
    int res[n];
    std::memset(res, 0, sizeof(res));
    int cur = 0;
    int cnt = 1;
    res[0] = 1;
    while(true){
        cur += k * cnt;
        if(res[cur % n] == 1){
            break;
        }else{
            res[cur % n] = 1;
            cnt += 1;
        }
    }

    std::vector<int> ans;
    for(int i = 0; i < n; ++i){
        if(res[i] == 0){
            ans.push_back(i + 1);
        }
    }
    return ans;

}
