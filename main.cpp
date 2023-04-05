#include <iostream>
#include "middle/leetcode1578.h"

int main() {
    leetcode1578 lc1578;
    string colors="abaac";
    vector<int> neededTime={1,2,3,4,5};

    std::cout<<lc1578.minCost(colors,neededTime);
    return 0;
}

