#include <iostream>
#include "simple/leetcode1640.h"


int main() {
    leetcode1640 lc1640;
    vector<int> arr={91,4,64,78};
    vector<vector<int>> pieces={
            {78},
            {4,64},
            {91}
    };
    std::cout<<lc1640.canFormArray(arr,pieces)<<std::endl;
    return 0;
}

