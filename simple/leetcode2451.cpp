//
// Created by 25467 on 2023/5/25.
//

#include "leetcode2451.h"
#include "unordered_map"
using std::string;
using std::unordered_map;
//
//        计算每个字符串的差分就行了
//        注意到如果我们对整个字符串加减同一个数, 差分结果不变
//        所以我们只需要把首字母都变成a, 然后比较字符串们是否相同就行了
std::string leetcode2451::oddString(std::vector<std::string> &words) {
    unordered_map<string,int> u_mp;
    unordered_map<string,string> u_map; //编码一下
    int n = words[0].size();
    for(auto word:words){
        string s;
        for(int i=1;i<n;i++) s+='a'+word[i]-word[i-1]; //从'a'开始，差分如果一样，那么这个s一样
        u_mp[s]++;
        u_map[s] = word;
    }
    for(auto &[k,v]:u_mp){
        if(v==1) return u_map[k];
    }
    return "";
}
