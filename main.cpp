#include <iostream>
#include "simple/leetcode2399.h"

int main() {
    leetcode2399 lc2399;
    vector<int> distance={49,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    string s="abbccddeeffgghhiijjkkllmmnnooppqqrrssttuuvvwwxxyyzza";
    std::cout<< lc2399.checkDistances(s,distance);
    return 0;
}

