//
// Created by skt on 2023/9/1.
//

#include "leetcode2240.h"

long long leetcode2240::waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long res = 0;
    int pen = total / cost1;
    for(int i = 0; i <= pen; ++i){
        int left = total - i * cost1;
        int pencil = left / cost2 + 1;
        res += pencil;
    }
    return res;
}
