//
// Created by 25467 on 2023/4/2.
//

#include "leetcode1039.h"
#include "functional"

int leetcode1039::minScoreTriangulation(vector<int> &values) {
    int n=values.size();

    vector<vector<int>> memo(n,vector<int>(n,-1));
    //means from i to j, lowest score
    std::function<int(int,int)> dfs=[&](int i, int j)->int{
        if(i+1==j)  return 0;
        int &res=memo[i][j];
        if(res!= -1) return res;
        res=INT_MAX;
        for(int k=i+1;k<j;++k){
            res=std::min(res,dfs(k,j)+dfs(i,k)+values[i]*values[j]*values[k]);
        }
        return res;
    };

    return dfs(0,n-1);

}

int leetcode1039::minScoreTriangulation1(vector<int> &values) {
    int n=values.size();

    vector<vector<int>> f(n,vector<int>(n,0));

    for(int i=n-3;i>=0;--i){
        for(int j=i+2;j<n;++j){
            f[i][j]=INT_MAX;
            for(int k=i+1;k<j;++k){
                f[i][j]= std::min(f[i][j],f[i][k]+f[k][j]+values[i]*values[j]*values[k]);
            }
        }
    }
    return f[0][n-1];
}