#include <iostream>
#include "simple/leetcode1688.h"

int main() {
    leetcode1688 lc1688;
    string sequence="aaaaabaaa";
    string word="a";
    std::cout<<lc1688.maxRepeating(sequence,word)<<std::endl;
    return 0;
}

