//
// Created by lzw on 2022/8/26.
//

#include "leetcode1464.h"

int leetcode1464::maxProduct(std::vector<int> &nums) {
//    int len = nums.size();
//    int max=0;
//    for(int i=0;i<len;i++){
//        for(int j=i+1;j<len;j++){
//            int temp=(nums[i]-1)*(nums[j]-1);
//            max= temp>max?temp:max;
//        }
//    }
//    return max;
    //即找到最大的和次大的数字
    int fmax=nums[0],smax=nums[1];
    int len=nums.size();
    if(fmax<smax){
        int temp=fmax;
        fmax=smax;
        smax=temp;
    }
    for(int i=2;i<len;i++){
        if(nums[i]>fmax){
            smax=fmax;
            fmax=nums[i];
        }else if(nums[i]>smax){
            smax=nums[i];
        }
    }
    return  (fmax-1)*(smax-1);

}

