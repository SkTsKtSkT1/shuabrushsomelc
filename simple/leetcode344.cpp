//
// Created by skt on 2023/8/7.
//

#include "leetcode344.h"

void leetcode344::reverseString(std::vector<char> &s) {
    size_t n = s.size();
    int l = 0, r = n - 1;
    while(l < r){
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        ++l;
        --r;
    }

}
