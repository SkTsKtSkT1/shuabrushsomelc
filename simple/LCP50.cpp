//
// Created by 25467 on 2023/9/15.
//

#include "LCP50.h"
#include <cmath>
#include <climits>
#include <algorithm>

int LCP50::giveGem(std::vector<int> &gem, std::vector<std::vector<int>> &operations) {
    for(const std::vector<int>& oper : operations){
        int from = oper[0];
        int to = oper[1];
        gem[to] += gem[from] / 2;
        gem[from] -= gem[from] / 2;
    }

    return *std::max_element(gem.begin(), gem.end()) - *std::min_element(gem.begin(), gem.end());
}
