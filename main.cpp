#include <iostream>
#include "middle/leetcode1053.h"

int main() {
    leetcode1053 lc1053;
    vector<vector<int>> arr={
            {3,1,1,3},
            {3,2,1},
            {1,1,5},
            {1,9,4,6,7}
    };
    for(vector<int>& a:arr){
        lc1053<<lc1053.prevPermOpt1(a);
    }
    return 0;
}

