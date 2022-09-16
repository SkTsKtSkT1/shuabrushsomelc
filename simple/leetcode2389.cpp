//
// Created by lzw on 2022/9/9.
//

#include "leetcode2389.h"
#include "algorithm"
#include "iostream"

vector<int> leetcode2389::answerQueries(vector<int> &nums, vector<int> &queries){
    //1排序
    //2求前缀和
    //3解答query，可以二分：找到小于query[i]的最大或者大于的最小index
    //4可以再nums基础进行修改，减小空间复杂度
    std::sort(nums.begin(), nums.end());
    for(int i=1;i<nums.size();i++){
        nums[i]+=nums[i-1];
    }
    for(int i=0;i<queries.size();i++){
        queries[i]= bisectRight(nums,queries[i]);
    }
    return queries;
}

//找到大于query[i]的最小下标
int leetcode2389::bisectRight(vector<int> &nums, int q) {
    if(nums.size()==0) return -1;
    if(q<nums[0]) return 0;
    if(q>=nums[nums.size()-1]) return nums.size();
    int l = 0;
    int r = nums.size()-1;
    while (r > l) { //结束条件为left==right
        int mid = l + ((r - l) >> 1);
        if (nums[mid] > q) {
            r = mid;//r=mid，因为寻找比q大的最小下标，因此如果mid比q大，则保留这个mid，可能mid-1就小于q了
        }else if (nums[mid] < q) {
            l = mid + 1;//mid比q小，那么left=mid+1;
        }else if(nums[mid]==q){
            return mid+1;  //与q相等，则最小下表为mid+1;
        }
    }
    return l;//left==right结束while循环，因此返回l
}

std::ostream &leetcode2389::operator<<(const vector<int> &nums) {
    for(vector<int>::const_iterator _=nums.begin();_!=nums.end();_++){
        std::cout<<*_<<" "<<std::endl;
    }

}
