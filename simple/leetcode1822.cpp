//
// Created by lzw on 2022/10/27.
//

#include "leetcode1822.h"

int leetcode1822::arraySign(vector<int> &nums) {
    int ans=1;
    for(int n:nums){
        if(n<0){
            ans*=-1;
        }else if(n==0){
            return 0;
        }
    }
    return ans;
}