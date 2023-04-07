//
// Created by skt on 2023/4/8.
//

#include "leetcode1125.h"
#include "unordered_map"
#include "functional"
//https://leetcode.cn/problems/smallest-sufficient-team/solution/zhuang-ya-0-1-bei-bao-cha-biao-fa-vs-shu-qode/
vector<int> leetcode1125::smallestSufficientTeam(vector<string> &req_skills, vector<vector<string>> &people) {
    std::unordered_map<string,int> sid;//make skill->int;
    int m=req_skills.size();
    for(int i=0; i<m; ++i){
        sid[req_skills[i]]=i;
    }
    //Then encode the people skill // 1 means can  011011_(2)
    int n=people.size();
    vector<int> mask(n,0);
    for(int i=0; i<n; ++i){
        for(auto &s:people[i]){
            mask[i]|= (1<<sid[s]);
        }
    }

    int U=1<<m;

    vector<vector<long long>>  memo(n,vector<long long>(U,-1));
    long long all = (1LL<<n)-1;

    //dfs(i,j) 定义成从前i 个集合中选择一些集合，并集等于j，所选择的最小下标集合
    std::function<long long(int,int)> dfs = [&](int i,int j)->long long{
        if(j==0)  return 0;
        if(i<0) return all;
        long long &res = memo[i][j];
        if(res!=-1) return res;//has been calculated;
        long long  res1= dfs(i-1,j); //do not choose i
        long long res2= dfs(i-1, j & ~mask[i])|(1LL<<i);//choose i, j & ~ 表示除去集合， ｜ 1<<i表示选择第i个
        return res= __builtin_popcountll(res1)<__builtin_popcountll(res2)? res1 : res2;
    };

    long long res=dfs(n-1, U-1);
    //decode
    vector<int> ans;
    for(int i=0;i<n;++i){
        if((res>>i)&1){
            ans.push_back(i);
        }
    }
    return ans;
}


std::ostream &leetcode1125::operator<<(const vector<int> v) {
    for(vector<int>::const_iterator it = v.begin(); it!= v.end(); it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
    return std::cout;
}