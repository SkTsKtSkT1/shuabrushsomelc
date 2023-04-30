//
// Created by skt on 2023/4/30.
//

#include "leetcode1033.h"
#include "algorithm"
vector<int> leetcode1033::numMovesStones(int a, int b, int c) {
    int p[] = {a, b, c};
    std::sort(p, p + 3);
    a = p[0]; b = p[1]; c = p[2];
    return {c - a == 2 ? 0 :
            b - a <= 2 || c - b <= 2 ? 1 : 2,
            c - a - 2};
}
