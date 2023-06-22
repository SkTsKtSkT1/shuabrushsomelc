//
// Created by 25467 on 2023/6/21.
//

#include "LCP41.h"
#include "functional"
#include "queue"
//https://leetcode.cn/problems/fHi6rV/solution/python3javacgo-yi-ti-yi-jie-bfs-by-lcbin-e4vo/
int LCP41::flipChess(std::vector<std::string> &chessboard) {
    int m = chessboard.size();
    int n = chessboard[0].size();
    std::function<int(int, int)> bfs = [&](int i, int j) -> int {
        std::queue<std::pair<int, int>> q;
        q.emplace(i,j);
        auto g = chessboard;
        g[i][j] = 'X';
        int cnt = 0;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            i = p.first;
            j = p.second;
            for(int a = -1; a <= 1; ++a){
                for(int b = -1; b <= 1; ++b){
                    if(a == 0 && b == 0){
                        continue;
                    }
                    int x = i + a, y = j + b;
                    while(x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 'O'){
                        x += a;
                        y += b;
                    }
                    if(x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 'X'){
                        x -= a;
                        y -= b;
                        cnt += std::max(std::abs(x - i), std::abs(y - j));
                        while(x != i || y != j){
                            g[x][y] = 'X';
                            q.emplace(x, y);
                            x -= a;
                            y -= b;
                        }
                    }
                }
            }
        }
        return cnt;
    };

    int ans = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(chessboard[i][j] == '.'){
                ans = std::max(ans, bfs(i, j));
            }
        }
    }
    return ans;
}
