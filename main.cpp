#include <iostream>

#include "leetcode646.h"

int main() {
    leetcode646 lc646;
    //[[-6,9],[1,6],[8,10],[-1,4],[-6,-2],[-9,8],[-5,3],[0,3]]
    std::vector<std::vector<int>> test={{-6,9},{1,6},{8,10},{-1,4},{-6,-2},{-9,8},{-5,3},{0,3}};
    int result=lc646.findLongestChain(test);
    std::cout<<result<<std::endl;
    return 0;
}

