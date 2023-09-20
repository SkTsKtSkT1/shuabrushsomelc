//
// Created by 25467 on 2023/9/20.
//

#include "LCP06.h"

int LCP06::minCount(std::vector<int> &coins) {
    int cnt = 0;
    for(int coin : coins){
        cnt += (coin % 2 == 0 ? coin /2 : coin / 2 + 1);
    }
    return cnt;
}
