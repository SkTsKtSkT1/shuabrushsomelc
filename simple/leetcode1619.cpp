//
// Created by skt on 2022/9/14.
//

#include "leetcode1619.h"

double leetcode1619::trimMean(vector<int> &arr) {
    std::sort(arr.begin(),arr.end());
    int sum=0;
    for(int i=arr.size()/20;i<arr.size()*19/20;i++){
        sum+=arr[i];
    }
    return 1.0*sum/(arr.size()*0.9);
}