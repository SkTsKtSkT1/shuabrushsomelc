#include <iostream>

#include "leetcode857.h"

int main() {
    leetcode857 lc857;
    vector<int> quality={10,20,5};
    vector<int> wage={70,50,30};
    int k=2;
    std::cout<<lc857.mincostToHireWorkers(quality,wage,k)<<std::endl;
    return 0;
}

