#include <iostream>
#include "hard/leetcode1000.h"

int main() {
    leetcode1000 lc1000;
    vector<int> stones={3,2,4,1};
    int k=2;
    std::cout<<lc1000.mergeStones(stones,k)<<std::endl;
    std::cout<<lc1000.mergeStones_opt(stones,k);
    return 0;
}

