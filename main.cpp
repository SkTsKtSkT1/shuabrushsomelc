#include <iostream>
#include "simple/leetcode2432.h"

int main() {
    leetcode2432 lc2432;
    vector<vector<int>> logs={
            {1,1},
            {3,7},
            {2,12},
            {7,17}
    };
    int n=26;
    std::cout<<lc2432.hardestWorker(n,logs)<<'\n';
    return 0;
}

