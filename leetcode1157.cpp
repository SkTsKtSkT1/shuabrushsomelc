//
// Created by 25467 on 2023/4/16.
//

#include <algorithm>
#include "leetcode1157.h"
#include "unordered_map"

MajorityChecker::MajorityChecker (vector<int> &arr) :arr(arr) {
    for(int i=0;i<arr.size();i++) m[arr[i]].push_back(i);
}
//返回数组区间 [left,right] 中至少出现threshold次的元素 超时
//int MajorityChecker::query(int left, int right, int threshold) {
//    for(auto& i:_map){
//        if(i.second.size()<threshold) continue;
//        auto it1= std::lower_bound(std::begin(i.second),std::end(i.second),left);
//        auto it2= std::upper_bound(std::begin(i.second),std::end(i.second),right);
//        if(it2-it1>=threshold) return i.first;
//    }
//    return  -1;
//}
//随机化
int MajorityChecker::query(int left, int right, int threshold) {
    int length=right-left+1;
    std::uniform_int_distribution<int> dis(left,right);

    for(int i=0;i<k;++i){
        int x=arr[dis(gen)];
        if(m[x].size()<threshold) continue;
        auto it1=std::lower_bound(m[x].begin(),m[x].end(),left);
        auto it2=std::upper_bound(m[x].begin(), m[x].end(),right);
        if(it2-it1>=threshold) return x;
        else if(2*(it2-it1)>=length) return -1;
    }
    return -1;
}