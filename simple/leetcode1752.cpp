//
// Created by lzw on 2022/11/27.
//

#include "leetcode1752.h"


bool leetcode1752::check(vector<int> &nums) {
    //如果我扩增这个数组，然后找到第一个满足a[i]>a[i+1]的，往后数n个，如果都满足则true；也就是把数组看成环，只存在一个情况
    int cnt=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>nums[(i+1)%nums.size()]) cnt++;
        if(cnt>1) return false;
    }
    return true;

}