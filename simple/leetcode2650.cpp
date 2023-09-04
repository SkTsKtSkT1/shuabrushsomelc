//
// Created by skt on 2023/9/5.
//

#include "leetcode2650.h"

int leetcode2650::minNumber(std::vector<int> &nums1, std::vector<int> &nums2) {
    //1.如果有都出现的，那么返回即可
    int num1[10] = {0};
    int num2[10] = {0};
    for(int num : nums1){
        num1[num] += 1;
    }
    for(int num : nums2){
        num2[num] += 1;
    }

    int min1 = 10, min2 = 10;
    for(int i = 0; i < 10; ++i){
        if(num1[i] != 0 && num2[i] != 0){
            return i;
        }
        if(num1[i] != 0){
            min1 = std::min(min1, i);
        }
        if(num2[i] != 0){
            min2 = std::min(min2, i);
        }
    }

    return min1 < min2 ? min1 * 10 + min2 : min2 * 10 + min1;
}
