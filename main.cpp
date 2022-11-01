#include <iostream>
#include "simple/leetcode1662.h"

int main() {
    leetcode1662 lc1662;
    vector<string> word1={"ab","c"};
    vector<string> word2={"a","bc"};
    std::cout<<lc1662.arrayStringsAreEqual(word1,word2)<<std::endl;
    return 0;
}

