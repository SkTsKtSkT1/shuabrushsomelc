//
// Created by 25467 on 2023/4/4.
//https://leetcode.cn/problems/minimum-cost-to-merge-stones/solution/tu-jie-qu-jian-dpzhuang-tai-she-ji-yu-yo-ppv0/
//

#include "leetcode1000.h"
#include "functional"
#include "map"
//k==2的时候一定存在答案，在k不等于2的时候，每次合并减少k-1个石头，最后生下一堆，假如石头总数（也就是数组原长度）模(k-1)的大小不是1，那么答案不存在。n-m*(k-1)=k->(n-1)%(k-1)==0;
int leetcode1000::mergeStones(vector<int> &stones, int k) {
    int n=stones.size();
    if((n-1)%(k-1)){
        return -1;
    }
    //区间dp
    // 定义状态：dp(i,j,p)->i到j合并为p堆最小的cost
    //定义状态转移方程：dp(i,j,p)=min(dfs(i,m,1)+dfs(m+1,j,p-1)); where m = i+(k-1)*x
    //dfs(i,j,1)=dfs(i,j,k)+sum.
    //初始化：dfs(i,i,1)=0;

    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+stones[i];
    }

    vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));

    std::function<int(int,int,int)> dfs=[&](int i,int j,int p)->int{
        int& res=dp[i][j][p];
        if(res!=-1) return res;
        if(p==1){
            return res= (i==j?0:dfs(i,j,k)+pre[j+1]-pre[i]);
        }
        res=INT_MAX;
        for(int m=i;m<j;m+=(k-1)){
            res=std::min(res,dfs(i,m,1)+dfs(m+1,j,p-1));
        }
        return res;
    };

    return dfs(0,n-1,1);
}

int leetcode1000::mergeStones_opt(vector<int> &stones, int k) {
    int n=stones.size();
    if((n-1)%(k-1)){
        return -1;
    }
    //区间dp
    // 定义状态：dp(i,j)->i到j合并到小于k堆最小的cost
    //定义状态转移方程：dp(i,j)=min(dfs(i,m,1)+dfs(m+1,j,k-1)); where m = i+(k-1)*x
    //m-i == (k-1)*x ->j-i = y(k-1)   else j-i %(k-1)!=0;
    //so: dp(i,j)=min(dfs(i,m)+dfs(m+1,j)+sum. and dfs(i,m)+dfs(m+1,k) //if mod==0 or not
    //dfs(i,j,1)=dfs(i,j,k)+sum.
    //初始化：dfs(i,i)=0;

    vector<int> pre(n+1,0);
    for(int i=0;i<n;i++){
        pre[i+1]=pre[i]+stones[i];
    }

    std::map<std::pair<int,int>,int> u_map;

    std::function<int(int,int)> dfs=[&](int i,int j)->int{
        if(i==j) return 0;

        if(u_map.count({i,j})){
            return u_map[{i,j}];
        }
        //if first time
        int res=INT_MAX;
        for(int m=i;m<j;m+=(k-1)){
            res=std::min(res,dfs(i,m)+dfs(m+1,j));
        }
        if((j-i)%(k-1)==0){
            res+=pre[j+1]-pre[i];
        }
        u_map[{i,j}]=res;
        return res;

    };

    return dfs(0,n-1);
}