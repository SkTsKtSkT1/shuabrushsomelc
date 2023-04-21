//
// Created by 25467 on 2023/4/20.
//

#include "leetcode1679.h"
#include "algorithm"

int leetcode1679::maxOperations(vector<int> &nums, int k) {
    std::sort(nums.begin(),nums.end(),[&](int a,int b)->bool{
       return a<b;
    });//asc;
    int res=0;
    int left=0,right=nums.size();
    while(left<right){
        if(nums[left]+nums[right]==k){
            left++;
            right--;
            res++;
        }else if(nums[left]+nums[right]<k){
            left++;
        }else{
            right--;
        }
    }
    return res;
}
