//
// Created by 25467 on 2023/4/23.
//

#include "leetcode2215.h"
#include "set"
vector<vector<int>> leetcode2215::findDifference(vector<int> &nums1, vector<int> &nums2) {
    std::set<int> s1;
    std::set<int> s2;
    for(int& n:nums1){
        s1.insert(n);
    }
    for(int &n:nums2){
        s1.erase(n);
        s2.insert(n);
    }
    for(int& n:nums1){
        s2.erase(n);
    }

    vector<vector<int>> res(2);
    res[0].assign(s1.begin(), s1.end());
    res[1].assign(s2.begin(),s2.end());
    return res;

}
