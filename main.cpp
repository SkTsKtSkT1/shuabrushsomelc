#include <iostream>

#include "leetcode827.h"


int main() {
    leetcode827 lc827;
    vector<vector<int>> grid={
            {0,1},
            {1,1}
    };
    std::cout<<lc827.largestIsland(grid)<<std::endl;
    return 0;
}

