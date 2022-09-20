//
// Created by skt on 2022/9/21.
//

#include "leetcode854.h"

int leetcode854::kSimilarity(std::string s1, std::string s2) {
    dfs(s1,s2,0,0);
    return ans;
}

void leetcode854::dfs(std::string& s1, std::string& s2, int cur, int step) {
    if(step>=ans) return;
    if(cur>=s1.size()){ //当前要处理的位置
        ans=std::min(ans,step);
        return ;
    }
    if(s1[cur]==s2[cur]){
        dfs(s1,s2,cur+1,step);
        return ;
    }
    //估计最少需要的步数 官方题解有介绍
    int cnt=0;
    for(int i=cur+1;i<s1.size();i++){
        if(s1[i]!=s2[i]){
            ++cnt;
        }
    }
    if(step+(cnt+1)/2>=ans) return ;
    for(int i=cur+1;i<s1.size();i++){
        if(s1[i]==s2[cur]){
            std::swap(s1[i],s1[cur]);
            //处理了cur，step+=1
            dfs(s1,s2,cur+1,step+1);
            //回溯
            std::swap(s1[i],s1[cur]);
        }
    }



}