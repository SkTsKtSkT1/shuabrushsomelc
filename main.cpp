#include <iostream>
#include "simple/leetcode1710.h"

int main() {
    leetcode1710 lc1710;
    vector<vector<int>> boxTypes={
            {1,3},{3,1},{2,2}
    };
    int truckSize=4;
    std::cout<<lc1710.maximumUnits(boxTypes,truckSize)<<std::endl;
    return 0;
}

