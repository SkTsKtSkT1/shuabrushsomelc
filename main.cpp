#include <iostream>
#include "leetcode801.h"


int main() {
    leetcode801 lc801;
    vector<int> nums1={0,7,8,10,10,11,12,13,19,18};
    vector<int> nums2={4,4,5,7,11,14,15,16,17,20};
    std::cout<<lc801.minSwap(nums1,nums2)<<std::endl;
    return 0;
}

