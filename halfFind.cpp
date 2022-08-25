#include "halfFind.h"

//int halfFind(std::vector<int>& nums,int target){
//    int right=nums.size()-1;
//    int left=0;
//    while (left<=right) {
//        int mid=left+((right-left)>>1);
//        if (nums[mid] > target) {
//            right=mid-1;
//        }
//        else if (nums[mid] < target ) {
//            left=mid+1;
//        }
//        else if(nums[mid]==target){
//            return mid;
//        }
//    }
//    return 0;
//
//}
int halfFind(std::vector<int>& nums,int target){
    int right=nums.size()-1;
    int left=0;
    int ans=right+1;
    while (left<=right) {
        int mid=left+((right-left)>>1);
        if (nums[mid] >= target) {
            ans=mid;
            right=mid-1;

        }
        else if (nums[mid] < target ) {
            left=mid+1;

        }
    }
    return ans;

}