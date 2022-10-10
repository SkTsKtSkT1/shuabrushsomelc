//
// Created by skt on 2022/10/10.
//

#include "leetcode801.h"


int leetcode801::minSwap(vector<int> &nums1, vector<int> &nums2) {
    //dp[i][0] 表示在nums1[i]和nums2[i]位置处，如果不交换位置的话，当前累积的操作次数。
    //dp[i][1] 表示在nums1[i]和nums2[i]位置处，如果交换位置的话，当前累积的操作次数。
    int len=nums1.size();
    vector<vector<int>> dp(len,vector<int>(2));
    dp[0][0]=0;
    dp[0][1]=1;
    for(int i=1;i<len;i++){
        int nums1a=nums1[i-1],nums1b=nums1[i],nums2a=nums2[i-1],nums2b=nums2[i];
        if((nums1a<nums1b && nums2a<nums2b)&&(nums1a<nums2b&&nums2a<nums1b)){
            //交换后依旧满足要求，则上一个可以换也可以不换，若没换上一个也不需要换，则第i次操作如果交换，则次数+1，不然的话可以是第i-1次最少
            // 的得到
            dp[i][0]=std::min(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i][0]+1;
        }else if(nums1a<nums1b && nums2a<nums2b){
            //交换后不满足要求，则i(bu)交换则i-1也要(bu)换
            dp[i][0]=dp[i-1][0];
            dp[i][1]=dp[i-1][1]+1;
        }else{
            //如果原本不递增，则i-1交换->i不交换，i-1不换->i换
            dp[i][0]=dp[i-1][1];
            dp[i][1]=dp[i-1][0]+1;
        }
    }
    return std::min(dp[len-1][0],dp[len-1][1]);
}