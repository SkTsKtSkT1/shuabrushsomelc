#include <iostream>
#include "middle/leetcode2679.h"

int main() {
    leetcode2679 lc2679;
    std::vector<std::vector<int>> nums = {
            {7, 2, 1},
            {6, 4, 2},
            {6, 5, 3},
            {3, 2, 1}
    };
    std::cout << lc2679.matrixSum(nums) << std::endl;
    return 0;
}

