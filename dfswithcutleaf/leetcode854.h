//
// Created by skt on 2022/9/21.
//

#ifndef ALGORITHM_LEETCODE854_H
#define ALGORITHM_LEETCODE854_H
#include "string"
#include "unordered_set"
using std::string;

class leetcode854 {
private:
    int ans=INT_MAX;
    int bfs(string s1,string s2);
    void dfs(string& s1,string& s2,int cur,int step);
public:
    int kSimilarity(string s1,string s2);
};


#endif //ALGORITHM_LEETCODE854_H
