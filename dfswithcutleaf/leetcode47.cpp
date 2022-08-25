//
// Created by lzw on 2022/8/23.
//

#include "leetcode47.h"

std::vector<std::vector<int>> leetcode47::permuteUnique(std::vector<int> &nums) {
    if(nums.size()==0) return result;
    std::vector<int> path;
    std::vector<bool> used;
    used.assign(nums.size(),false);
    std::sort(nums.begin(), nums.end());
    dfs(nums,path,used);
    return result;
}

void leetcode47::dfs(std::vector<int> nums, std::vector<int> path, std::vector<bool> used) {
    if(path.size()==nums.size()){
        result.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]==true)  continue;
        if(i>0 && nums[i]==nums[i-1] && used[i-1]==false) continue;
        used[i]=true;
        path.push_back(nums[i]);
        dfs(nums,path,used);
        path.erase(path.end()-1,path.end());
        used[i]=false;
    }
}