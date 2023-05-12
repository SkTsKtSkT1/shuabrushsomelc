//
// Created by 25467 on 2023/5/12.
//

#include "leetcode1330.h"
#include "iostream"
//https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value/solution/bu-hui-hua-jian-qing-kan-zhe-pythonjavac-c2s6/
// for [i,j], 如果反转， 那么改变的值有哪些？
// i i+1 i+2 ,   j-1 j -> j j-1 j-2   .... i+2 i+1 i;
//delta = |i-1| - |i| |j| - |j+1|  |||  |i-1| - |j| |i| - |j+1| where 0<i<j<n-1;
// let a = nums[i-1],b=nums[i],x=nums[j],y=nums[j+1];
//d = -|a-b|-|x-y|+|a-x|+|b-y|
//|a-b| = max(a,b)-min(a,b) ,a+b = max(a,b)+min(a,b)
//then: a+b+|a-b| = 2max(a,b) and a+b - |a-b| = 2min(a,b)
int leetcode1330::maxValueAfterReverse(vector<int> &nums) {
    int base = 0, d=0, mx=INT_MIN, mn=INT_MAX, n =nums.size();
    for(int i=1;i<n;i++){
        int a = nums[i-1], b=nums[i];
        base += std::abs(a-b);
        mx = std::max(mx,std::min(a,b));
        mn = std::min(mn,std::max(a,b));
        d= std::max(d, std::max(std::abs(nums[0]-b)-std::abs(a-b), // i =0;
                                std::abs(nums[i-1]-a)-std::abs(a-b))); //j=n-1;
    }
    return base + std::max(d,2*(mx-mn));
}
