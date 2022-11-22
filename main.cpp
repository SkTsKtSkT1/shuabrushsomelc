#include <iostream>
#include "leetcode878.h"

int main() {
    leetcode878 lc878;
    std::vector<std::vector<int>> par={
            {4,2,3},
            {2,7,3},
            {1,2,3},
            {5,2,3},
            {10,10,8},
            {1000000000,40000,40000}
    };
    for(std::vector<int>& p:par){
        std::cout<<lc878.nthMagicalNumber(p[0],p[1],p[2])<<std::endl;
    }
    return 0;
}

