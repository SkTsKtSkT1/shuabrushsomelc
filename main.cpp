#include <iostream>
#include "middle/leetcode1072.h"

int main() {
    leetcode1072 lc1072;
    vector<vector<int>> matrix={
            {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
            {1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1},
            {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
            {1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1}
    };
    std::cout<<lc1072.maxEqualRowsAfterFlips(matrix)<<'\n';
    return 0;
}

