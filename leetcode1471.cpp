//
// Created by lzw on 2022/8/29.
//

#include "leetcode1471.h"

std::vector<int> leetcode1471::getStrongest(std::vector<int>& arr, int k) {
    int len=arr.size();
    std::sort(arr.begin(),arr.end());
    int midNum=arr[(len-1)>>1];
    std::vector<int> result;
    int left=0,right=len-1;
    while (result.size()<k){
        if(midNum-arr[left] > arr[right]-midNum){
            result.push_back(arr[left++]);
        }else{
            result.push_back(arr[right--]);
        }
    }
    return result;
}