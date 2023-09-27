//
// Created by 25467 on 2023/9/27.
//

#include "leetcode1333.h"
#include <algorithm>
std::vector<int>
leetcode1333::filterRestaurants(std::vector<std::vector<int>> &restaurants, int veganFriendly, int maxPrice,
                                int maxDistance) {
    int n = restaurants.size();
    std::vector<std::vector<int>> filtered;
    for (int i = 0; i < n; i++) {
        if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && !(veganFriendly && !restaurants[i][2])) {
            filtered.push_back(restaurants[i]);
        }
    }
    sort(filtered.begin(), filtered.end(), [](std::vector<int> &v1, std::vector<int> &v2) -> bool {
        return v1[1] > v2[1] || (v1[1] == v2[1] && v1[0] > v2[0]);
    });
    std::vector<int> res;
    for (auto &v : filtered) {
        res.push_back(v[0]);
    }
    return res;
}
