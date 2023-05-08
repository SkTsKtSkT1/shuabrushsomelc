//
// Created by 25467 on 2023/5/8.
//

#include "leetcode1263.h"
#include "queue"
#include "set"
#include "numeric"
using std::queue;

int minPushBox(vector<vector<char>> &grid) {
    // pq，[0]当前状态最小推箱子次数 [1]人的坐标x [2]人的坐标y [3]箱子的坐标x [4]箱子的坐标y
    std::priority_queue<vector<size_t>, vector<vector<size_t>>, std::greater<vector<size_t>>> pq;
    size_t m = grid.size();
    size_t n = grid[0].size();

    vector<size_t> a(5, 0);
    for (size_t x = 0; x < m; x++) {
        for (size_t y = 0; y < n; y++) {
            if (grid[x][y] == 'S') {
                a[1] = x;
                a[2] = y;
                grid[x][y] = '.';
            } else if (grid[x][y] == 'B') {
                a[3] = x;
                a[4] = y;
                grid[x][y] = '.';
            }
        }
    }
    pq.push(a);

    std::set<vector<size_t>> dist;
    dist.insert({a[1], a[2], a[3], a[4]});
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!pq.empty()) {
        auto v = pq.top();
        pq.pop();

        for (int i = 0; i < 4; i++) {
            vector<size_t> next_s = {v[1] + dx[i], v[2] + dy[i]};
            if (next_s[0] >= m || next_s[1] >= n || grid[next_s[0]][next_s[1]] == '#') {
                continue;
            }
            vector<size_t> next_b = {v[3], v[4]};
            size_t d = v[0];
            if (next_s == next_b) {
                next_b[0] += dx[i];
                next_b[1] += dy[i];
                if (next_b[0] >= m || next_b[1] >= n || grid[next_b[0]][next_b[1]] == '#') {
                    continue;
                }
                d++;
            }
            if (grid[next_b[0]][next_b[1]] == 'T') {
                return (int) d;
            }

            if (dist.find({next_s[0], next_s[1], next_b[0], next_b[1]}) != dist.end()) {
                continue;
            }
            dist.insert({next_s[0], next_s[1], next_b[0], next_b[1]});
            pq.push({d, next_s[0], next_s[1], next_b[0], next_b[1]});
        }
    }
    return -1;
}

