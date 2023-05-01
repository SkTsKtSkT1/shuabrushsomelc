//
// Created by 25467 on 2023/5/1.
//

#include "leetcode1376.h"
#include "functional"
int leetcode1376::numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime) {
    vector<vector<int>> tree(n);
    for(int i=0;i<n;i++){
        if(manager[i]>=0){
            tree[manager[i]].push_back(i);
        }
    }
    std::function<int(int)> dfs=[&](int x)->int{
        int max_path_sum=0;
        for(int& y:tree[x]){
            max_path_sum=std::max(max_path_sum, dfs(y));
        }
        return max_path_sum+informTime[x];
    };

    return dfs(headID);

}
