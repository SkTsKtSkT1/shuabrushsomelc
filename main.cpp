#include <iostream>
#include "hard/leetcode1335.h"

int main() {
    leetcode1335 lc1335;
    vector<int> jobDifficulty = {6,5,4,3,2,1};
    int d = 2;
    std::cout<<lc1335.minDifficulty(jobDifficulty,d);
    return 0;
}

