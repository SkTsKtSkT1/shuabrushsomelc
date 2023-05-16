//
// Created by 25467 on 2023/5/16.
//

#include "leetcode1335.h"
#include "functional"
#include "cstring"
int leetcode1335::minDifficulty(vector<int> &jobDifficulty, int d) {
    int n = jobDifficulty.size();
    if(n<d) return -1;
    vector<vector<int>> memo(d,vector<int>(n,-1));
    //int memo[d][n];
    //memset(memo,-1,sizeof(memo));
    std::function<int(int,int)> dfs = [&](int i,int j)->int{
        int &res = memo[i][j];
        if(res!=-1) return res;
        if(i == 0){
            int mx = 0;
            for(int k=0;k<=j;k++){
                mx = std::max(mx, jobDifficulty[k]);
            }
            res = mx;
            return  res;
        }
        res = INT_MAX;
        int mx=0;
        for(int k=j;k>=i;k--){
            mx = std::max(mx,jobDifficulty[k]);
            res = std::min(res,dfs(i-1,k-1)+mx);
        }
        return res;
    };

    return dfs(d-1,n-1);
}

