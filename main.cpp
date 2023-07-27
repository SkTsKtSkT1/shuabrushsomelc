#include <iostream>
#include "hard/leetcode2569.h"

int main() {
    leetcode2569 lc2569;
    std::vector<int> nums1 = {1, 0, 1};
    std::vector<int> nums2 = {0, 0, 0};
    std::vector<std::vector<int>> queries = {
            {1, 1, 1},
            {2, 1, 0},
            {3, 0, 0}
    };

    std::vector<long long> res = lc2569.handleQuery(nums1, nums2, queries);
    for(std::vector<long long>::iterator it = res.begin(); it != res.end(); ++it){
        std::cout << *it << std::endl;
    }
    return 0;
}

