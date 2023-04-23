//
// Created by 25467 on 2023/4/23.
//

#include <algorithm>
#include "leetcode1207.h"
//给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
//
//如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
bool leetcode1207::uniqueOccurrences(vector<int> &arr) {
    int cnt[2001]={0};
    for(int i=0;i<arr.size();++i){
        cnt[arr[i]+1000]++;
    }
    bool freq[1001]={false};
    for(int i=0;i<=2000;++i){
        if(cnt[i]){
            if(freq[cnt[i]]==false) freq[cnt[i]]=true;
            else return false;
        }
    }
    return true;
}
