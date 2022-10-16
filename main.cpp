#include <iostream>
#include "leetcode886.h"


int main() {
    leetcode886 lc886;
    vector<vector<int>> dislikes={
            {1,2},
            {2,3},
            {3,4},
            {4,5},
            {5,1}
    };
    int n=5;
    std::cout<<lc886.possibelBipartitin(n,dislikes)<<std::endl;
    return 0;
}

