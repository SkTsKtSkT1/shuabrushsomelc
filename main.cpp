#include <iostream>
#include "simple/leetcode1779.h"

int main() {
    leetcode1779 lc1779;

    int x=3;
    int y=4;
    vector<vector<int>> points={
            {1,2},{3,1},{2,4},{2,3},{4,4}
    };
    std::cout<<lc1779.nearestValidPoint(x,y,points)<<std::endl;
   return 0;
}

