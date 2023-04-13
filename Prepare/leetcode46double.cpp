//
// Created by 25467 on 2023/4/12.
//

#include "leetcode46double.h"
#include "functional"

vector<vector<int>> leetcode46double::permute(vector<int> &nums) {
    if(nums.size()==0) return res;
    vector<int> used(nums.size(),0);
    vector<int> path;
    dfs(nums,used,path);
    return res;
}

void leetcode46double::dfs(vector<int> &nums, vector<int> &used, vector<int>& path) {
    if(path.size()==nums.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(used[i]==1) continue;
        used[i]=1;
        path.push_back(nums[i]);
        dfs(nums,used,path);
        path.pop_back();
        used[i]=0;
    }
    return ;
}

std::ostream &leetcode46double::operator<<(const vector<vector<int>> &v) {
    for(auto it=v.begin();it!=v.end();++it){
        for(auto _=(*it).begin();_!=(*it).end();_++){
            std::cout<<*_<<" ";
        }
        std::cout<<'\n';
    }
    std::cout<<std::flush;
    return std::cout;
}

