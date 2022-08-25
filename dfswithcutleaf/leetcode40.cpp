//
// Created by skt on 2022/8/23.
//

#include "leetcode40.h"


std::vector<std::vector<int>> leetcode40::combinationSum2(std::vector<int> &candidates, int target) {
    if(candidates.size()==0) return result;
    std::vector<int> path;
    std::sort(candidates.begin(),candidates.end());

    std::vector<bool> used;
    used.assign(candidates.size(),false);
    dfs(candidates,path,used,0,0,target);

    return result;
}

void leetcode40::dfs(std::vector<int> &nums, std::vector<int> path,std::vector<bool> used, int start, int sum, int target) {
    if(sum==target){
        result.push_back(path);
        return;
    }

    for(int i=start;i<nums.size() && sum+nums[i]<=target;i++){
        if(used[i]) continue;
        if(i>0 && nums[i-1]==nums[i] && !used[i - 1]) continue;
        used[i]=true;
        path.push_back(nums[i]);
        dfs(nums,path,used,i,sum+nums[i],target);
        //path.erase(path.end()-1,path.end());
        path.pop_back();
        used[i]=false;
    }
}

