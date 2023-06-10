//
// Created by 25467 on 2023/6/10.
//


#include "leetcode1170.h"
#include "map"
using std::vector;
using std::string;

std::vector<int> leetcode1170::numSmallerByFrequency(vector<std::string> &queries, vector<std::string> &words) {
    std::map<int, int> query; //index, count;
    std::map<int, int> word; //count, nums;
    for(int i = 0; i < queries.size(); i++){
        query[i] = countCnt(queries[i]);
    }
    for(auto w:words){
        word[countCnt(w)]++;
    }
    vector<int> res;
    for(int i = 0; i < query.size(); i++){
        int ans = 0;
        int cur = query[i];
        for(auto &[count,nums] : word){
            if(count > cur){
                ans += nums;
            }
        }
        res.push_back(ans);
    }
    return res;
}

int leetcode1170::countCnt(string &s) {
    int cnt[26] = {0};
    for(char& c:s){
        cnt[c - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        if(cnt[i] != 0){
            return cnt[i];
        }
    }
    return -1;
}
