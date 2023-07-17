//
// Created by 25467 on 2023/7/17.
//

#include "leetcode415.h"
#include "algorithm"
std::string leetcode415::addStrings(std::string num1, std::string num2) {
    int i = num1.size() - 1, j = num2.size() - 1;
    int carry = 0;
    std::string res;
    while(i >=0 || j >= 0){
        int x = (i >= 0 ? num1[i] - '0' : 0);
        int y = (j >= 0 ? num2[j] - '0' : 0);
        int sum = carry + x + y;
        carry = sum / 10;
        sum = sum % 10;
        res.push_back(sum + '0');
        --i;
        --j;
    }
    if(carry){
        res.push_back(carry + '0');
    }

    std::reverse(res.begin(), res.end());
    return res;
}
