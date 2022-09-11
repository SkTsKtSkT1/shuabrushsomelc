//
// Created by skt on 2022/9/12.
//

#include "leetcode1608.h"

int leetcode1608::specialArray(vector<int> &nums) {
    //二分查找，找到大于等于x的最小下标
    std::sort(nums.begin(),nums.end());
    int len=nums.size();
    int n=nums[len-1];
    //感觉这里可以继续用二分优化
//    for(int i=0;i<=n;i++){
//        int bnum=len- bitsecIndex(nums,i);
//        if(bnum==i){
//            return bnum;
//        }
//    }
    int l=0;
    int r=n;
    while(r>=l){//可能是边界
        int mid=l+(r-l)/2;
        int bnum=len- bitsecIndex(nums,mid);
        if(bnum>mid){
            l=mid+1;
        }else if(bnum<mid){
            r=mid-1;
        }else if(bnum==mid){
            return bnum;
        }
    }
    return -1;
}

int leetcode1608::bitsecIndex(vector<int> &nums, int x) {
    //[0,n-1]寻找
    int len=nums.size();
    int l=0;
    int r=len-1;
    while(r>l){
        int mid=l+(r-l)/2;
        if(nums[mid]<x){
            l=mid+1;
            //找到大于等于x的最小下标
        }else if(nums[mid]>=x){
            r=mid;
        }
    }
    return l;

}