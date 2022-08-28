//
// Created by lzw on 2022/8/28.
//

#include "leetcode793.h"

int leetcode793::preimageSizeFZF(int k) {
    return f(k+1)-f(k);
}

int leetcode793::f(int k) {
    long left=0;
    long right=5L*k;
    long ans=right;
    //二分查找，找到第一个等于k的阶乘
    while(left<=right){
        long mid=left+((right-left)>>1);
        if(getCnt(mid)>=k){
            right=mid-1;
            ans=right;
        }else{
            left=mid+1;
        }
    }
    return ans;

    return ans;
}

/*
 * get cnt of 5
 */
long leetcode793::getCnt(long x) {
    long ans=0;
    //先找出5 然后25 5^3的个数
    while(x!=0){
        ans+=x/5;
        x/=5;
    }
    return ans;
}