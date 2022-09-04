#include <iostream>

#include "simple/leetcode1582.h"

int main() {
    leetcode1582 lc1582;
    std::vector<std::vector<int>> test={{1,0,0},{0,0,1},{1,0,0}};
    std::cout<<lc1582.numSpecial(test)<<std::endl;
    return 0;
}

