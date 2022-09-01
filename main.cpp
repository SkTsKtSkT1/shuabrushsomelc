#include <iostream>

#include "simple/leetcode1475.h"

int main() {
    leetcode1475 lc1475;
    std::vector<int> prices={10,1,1,6};
    std::vector<int> result=lc1475.finalPrices(prices);
    for(std::vector<int>::iterator _=result.begin();_!=result.end();_++){
        std::cout<<*_<<" ";
    }
    return 0;
}

