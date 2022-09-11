#include <iostream>

#include "simple/leetcode1608.h"

int main() {
    leetcode1608 lc1608;
    vector<vector<int>> test={
            {3,5},
            {0,0},
            {0,4,3,0,4},
            {3,6,7,7,0}
    };
    for(auto & i : test){
        std::cout << lc1608.specialArray(i) << std::endl;
    }
    return 0;
}

