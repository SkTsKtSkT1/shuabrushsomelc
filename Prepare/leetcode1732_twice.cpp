//
// Created by skt on 2023/4/22.
//

#include <algorithm>
#include "leetcode1732_twice.h"

int leetcode1732_twice::largestAltitude_twice(vector<int> &gain) {
    int max=0;
    vector<int> prefix(gain.size()+1,0);
    for(int i=1;i<prefix.size();++i){
        prefix[i]=prefix[i-1]+gain[i-1];
    }
    return *std::max_element(prefix.begin(), prefix.end());
}
