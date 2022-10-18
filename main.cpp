#include <iostream>
#include "leetcode902.h"


int main() {
    leetcode902 lc902;
    int n=8;
    vector<string> digits={"7"};
    std::cout<<lc902.atMostNGivenDigitSet(digits,n)<<std::endl;
    return 0;
}

