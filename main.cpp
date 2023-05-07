#include <iostream>
#include "middle/leetcode1010.h"

int main() {
    leetcode1010 lc1010;
    vector<int> time{15,63,451,213,37,209,343,319};

    std::cout<<lc1010.numPairsDivisibleBy60(time)<<'\n';
    return 0;
}

