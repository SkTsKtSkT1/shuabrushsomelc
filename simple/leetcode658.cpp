//
// Created by lzw on 2022/8/25.
//

#include "leetcode658.h"


std::vector<int> leetcode658::findClosestElements(std::vector<int>& arr, int k, int x) {
    //二分查找，找到第一个大于等于x的位置，然后使用左右指针来寻找对应的数
    int len=arr.size();
    int left=0;
    int right=len-1;
    while(left<right){
        int mid=left+((right-left)>>1);
        if(arr[mid]>=x){
            right=mid;
        }else{
            left=mid+1;
        }
    }
    int r = right, l = r - 1;
    std::vector<int> result;
    for (int i = 0; i < k; i++) {
        if (l < 0) {
            result.push_back(arr[r++]);
        } else if (r >= len) {
            result.push_back(arr[l--]);
        } else {
            if ((arr[r] - x) < (x - arr[l])) {
                result.push_back(arr[r++]);
            } else {
                result.push_back(arr[l--]);
            }
        }
    }

    std::sort(result.begin(),result.end());
    return result;
}