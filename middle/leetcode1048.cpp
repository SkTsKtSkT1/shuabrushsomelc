//
// Created by 25467 on 2023/4/27.
//

#include "leetcode1048.h"
#include "unordered_map"
#include "functional"
int leetcode1048::longestStrChain(vector<string> &words) {
    std::unordered_map<string,int> ws;
    for(string& w:words){
        ws[w]=0;
    }
    std::function<int(string)> dfs=[&](string s)->int{
        int res=ws[s];
        if(res) return res;
        for(int i=0;i<s.length();++i){
            string t=s.substr(0,i)+s.substr(i+1);
            if(ws.count(t)){
                res=std::max(res,dfs(t));
            }
        }
        return ws[s]=res+1;
    };
    int ans=0;
    for(auto &[s,_]:ws){
        ans=std::max(ans,dfs(s));
    }
    return ans;

}
