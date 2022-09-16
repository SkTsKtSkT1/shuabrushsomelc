#include <iostream>

#include "leetcode850.h"

int main() {
    leetcode850 lc850;
    vector<vector<int>> rectangles={
            {0,0,2,2},
            {1,1,3,3}
    };
    std::cout<<lc850.rectangleArea(rectangles)<<std::endl;
    return 0;
}

