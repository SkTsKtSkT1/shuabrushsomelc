#include <iostream>
#include "leetcode927.h"


int main() {
    leetcode927 lc927;
    vector<int> arr={1,1,0,1,1,1,0,1};
    vector<int> result=lc927.threeEqualParts(arr);
    std::cout<<result[0]<<" "<<result[1]<<std::endl;
    return 0;
}

