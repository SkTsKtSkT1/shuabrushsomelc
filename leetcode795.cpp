//
// Created by lzw on 2022/11/24.
//

#include "leetcode795.h"

int leetcode795::numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    //[left,right]->[0,right]-[0,left-1];
    auto f=[&](int x)->int{
        int cnt=0,t=0;
        for(int& v:nums){
            t=v>x?0:t+1; //长度为n的子数组个数就是从1+...+n
            cnt+=t;
        }
        return cnt;
    };

    return f(right)-f(left-1);


}
