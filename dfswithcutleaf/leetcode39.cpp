//
// Created by lzw on 2022/8/23.
//

#include "leetcode39.h"

std::vector<std::vector<int>> leetcode39::combinationSum(std::vector<int> &candidates, int target) {
    if(candidates.size()==0) return result;
    std::vector<int> path;
    std::sort(candidates.begin(),candidates.end());
    dfs(candidates,path,0,0,target);
    return result;
}

void leetcode39::dfs(std::vector<int> &nums, std::vector<int> path, int start,int sum, int target) {
    if(sum==target){
        result.push_back(path);
        return;
    }
   for(int i=start;i<nums.size() && sum+nums[i]<=target;i++){
        path.push_back(nums[i]);
        dfs(nums,path,i,sum+nums[i],target);
        path.erase(path.end()-1,path.end());
   }

}
