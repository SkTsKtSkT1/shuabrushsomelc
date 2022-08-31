#include <iostream>
#include <vector>
#include "leetcode946.h"

int main() {
    leetcode946 lc946;
    std::vector<int> pushed={1,2,3,4,5};
    std::vector<int> poped={4,5,3,2,1};
    std::cout<<lc946.validateStackSequences(pushed,poped);
    return 0;
}

