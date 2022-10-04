//
// Created by skt on 2022/10/5.
//

#include "leetcode811.h"

vector<string> leetcode811::subdomainVisits(vector<string> &cpdomains) {
    vector<string> ans;
    std::unordered_map<string,int> counts;
    for(string& cpdomain:cpdomains){
        int spaceIndex=cpdomain.find(' ');
        int count= std::stoi(cpdomain.substr(0,spaceIndex));
        string domain=cpdomain.substr(spaceIndex+1);
        counts[domain]+=count;
        //处理每个子域名(往后数,也就是往根域名靠近
        for(int i=0;i<domain.size();i++){
            if(domain[i]=='.'){
                string subdomain=domain.substr(i+1);
                counts[subdomain]+=count;
            }
        }
    }
    //获得结果
    for(std::pair<string,int> c:counts){
        ans.push_back(std::to_string(c.second)+" "+c.first);
    }
    return ans;
}
