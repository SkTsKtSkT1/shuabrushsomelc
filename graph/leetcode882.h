//
// Created by lzw on 2022/11/26.
//

#ifndef ALGORITHM_LEETCODE882_H
#define ALGORITHM_LEETCODE882_H
#include "vector"
#include "queue"
#include "utility"
using std::pair;
using std::priority_queue;
using std::vector;
//https://leetcode.cn/problems/reachable-nodes-in-subdivided-graph/solution/tu-jie-zhuan-huan-cheng-dan-yuan-zui-dua-6l8o/
class leetcode882 {
private:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &g, int start);
public:
    int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n);
};


#endif //ALGORITHM_LEETCODE882_H
