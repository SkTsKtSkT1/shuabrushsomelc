#include <iostream>
#include "mianshi/mianshi_16_19.h"

int main() {
    mianshi_16_19 ms_16_19;
    std::vector<std::vector<int>> land = {
            {0, 2, 1, 0},
            {0, 1, 0, 1},
            {1, 1, 0, 1},
            {0, 1, 0, 1}
    };
    std::vector<int> res= ms_16_19.pondSizes(land);
    for(std::vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        std::cout<< *it << '\t';
    }
    std::cout<<std::endl;
    return 0;
}

