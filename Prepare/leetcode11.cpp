//
// Created by 25467 on 2023/4/20.
//

#include "leetcode11.h"

int leetcode11::maxArea(vector<int> &height) {
    int left=0,right=height.size()-1;
    int max_area=0;
    while(left<right){
        max_area=std::max(max_area,std::min(height[left],height[right])*(right-left));
        if(height[right]>height[left]){
            left++;
        }else{
            right--;
        }
    }
    return max_area;
}
