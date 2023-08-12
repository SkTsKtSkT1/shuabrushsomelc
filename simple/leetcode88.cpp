//
// Created by skt on 2023/8/13.
//

#include "leetcode88.h"

void leetcode88::merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    //从大到小逆序插入
    if(m == 0) nums1 = nums2;
    int cur = m + n - 1;
    while(n){
        if(m == 0 || nums2[n - 1] > nums1[m - 1]){
            nums1[cur] = nums2[n - 1];
            n -= 1;
            --cur;
        }else{
            nums1[cur] = nums1[m - 1];
            m -= 1;
            --cur;
        }
    }
}
