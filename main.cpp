#include <iostream>
#include "dfswithcutleaf/leetcode698.h"


int main() {
    leetcode698 lc698;
    vector<int> nums{4,3,2,3,5,2,1};
    int k=4;
    std::cout<<lc698.canPartitionKSubsets(nums,k)<<std::endl;
    return 0;
}

