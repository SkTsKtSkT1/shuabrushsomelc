//
// Created by lzw on 2022/8/23.
//

#include "leetcode46.h"


std::vector<std::vector<int>> leetcode46::permute(std::vector<int> &nums) {
    if(nums.size()==0) return result;
    std::vector<int> path;
    std::vector<bool> used;
    used.assign(nums.size(),false);
    dfs(nums,path,used);
    return result;
}

void leetcode46::dfs(std::vector<int> nums, std::vector<int> path, std::vector<bool> used) {
    if(path.size()==nums.size()){
        result.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]==true)  continue;
        used[i]=true;
        path.push_back(nums[i]);
        dfs(nums,path,used);
        path.erase(path.end()-1,path.end());
        used[i]=false;
    }
}