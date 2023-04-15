//
// Created by 25467 on 2023/4/14.
//

#include "leetcode1023.h"
using std::vector;
using std::string;

//如果我们可以将小写字母插入模式串pattern得到待查询项query，那么待查询项与给定模式串匹配。（我们可以在任何位置插入每个字符，也可以插入 0 个字符。）
//对于queries[i]，是否可以在pattern的基础上，在pattern的**任意位置**加上**任意数目**（包括0个）**小写字母**得到queries[i]，如果可以ans[i]为true，否则为false。
vector<bool> leetcode1023::camelMatch(vector <string> &queries, string pattern) {
    vector<bool> res;
    int n=queries.size();
    for(string& query:queries){
        int j=0;
        for(int i=0; i<query.size(); i++){
            if(j<pattern.size() && query[i]==pattern[j]){
                j++;
            }else if(isupper(query[i])){
                j=0;
                break;
            }
        }
        if(j==pattern.size()){
            res.push_back(true);
        }else{
            res.push_back(false);
        }
    }
    return res;
}
