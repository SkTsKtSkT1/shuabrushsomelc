//
// Created by skt on 2023/8/22.
//

#include "leetcode849.h"

int leetcode849::maxDistToClosest(std::vector<int> &seats) {

    int res = 0, p1 = 0, p2;
    while (p1 < seats.size() && !seats[p1]) ++p1;
    res = p2 = p1;

    while (p2 < seats.size()) {
        while (p2 < seats.size() && !seats[p2]) ++p2; //find the next 1
        if (p2 == seats.size()) res = std::max(res, p2 - p1 - 1);
        else res = std::max(res, (p2 - p1) / 2);
        p1 = p2++;
    }
    return res;
}