#include <iostream>
#include "Prepare/leetcode643.h"

int main() {
    leetcode643 lc643;
    vector<int> nums={0,4,0,3,2};
    int k=1;
    std::cout<<lc643.findMaxAverage(nums,k)<<'\n';
    return 0;
}

