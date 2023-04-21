//
// Created by 25467 on 2023/4/21.
//

#include "leetcode643.h"

double leetcode643::findMaxAverage(vector<int> &nums, int k) {
    int left=0,right=k-1;
    //begin
    int sum=0;
    for(int i=left;i<=right;++i){
        sum+=nums[i];
    }
    int tmp=sum;
    //then find max;
    while(right+1<nums.size()){
        tmp=tmp-nums[left]+nums[right+1];
        sum=std::max(sum,tmp);
        left++;
        right++;
    }

    return 1.0*sum/k;
}
