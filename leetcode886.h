//
// Created by lzw on 2022/10/16.
//

#ifndef ALGORITHM_LEETCODE886_H
#define ALGORITHM_LEETCODE886_H
#include "vector"
#include "set"
#include "algorithm"

using std::vector;

class leetcode886 {
private:
    bool dfs(vector<vector<int>>& disMat,vector<int>& par,int index,int group,int n);
public:
    bool possibelBipartitin(int n,vector<vector<int>>& dislikes);
};


#endif //ALGORITHM_LEETCODE886_H
