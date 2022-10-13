//
// Created by lzw on 2022/10/13.
//

#include "leetcode769.h"
//因为数组 arr 的元素在区间[0,n−1] 之间且互不相同，所以数组排序后有 arr[i]=i。如果数组 arr 的某个长为 i+1的前缀块
//[a0,ai] 的最大值等于 i，那么说明它排序后与原数组排序后的结果一致。
int leetcode769::maxChunksToSorted(vector<int> &arr) {
    int res=0;
    int max=0;
    for(int i=0;i<arr.size();i++){
        max=std::max(arr[i],max);
        if(max==i){
            res++;
        }
    }
    return res;

}