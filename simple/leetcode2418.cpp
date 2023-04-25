//
// Created by 25467 on 2023/4/25.
//

#include "leetcode2418.h"
#include "algorithm"
#include "numeric"

vector<string> leetcode2418::sortPeople(vector<string> &names, vector<int> &heights) {
    int n=names.size();
    vector<int> idx(n);
    iota(idx.begin(),idx.end(),0);
    std::sort(idx.begin(),idx.end(),[&](int i,int j)->bool{
        return heights[i]>heights[j];
    });
    vector<string> res;
    for(int & i:idx){
        res.push_back(names[i]);
    }
    return res;
}
