
// Created by 25467 on 2023/8/17.
//

#include "leetcode1444.h"
#include <functional>
#include <cstring>

int leetcode1444::ways(std::vector<std::string> &pizza, int k) {
    const int MOD = 1e9 + 7;
    // 二维前缀和模板（'A' 的 ASCII 码最低位为 1，'.' 的 ASCII 码最低位为 0）
    int m = pizza.size(), n = pizza[0].size();
//    int memo[k][m][n];
//    memset(memo, -1, sizeof(memo));
    sum = std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + (pizza[i][j] & 1);//统计苹果个数
        }
    }
//    std::function<int(int, int, int)> dfs = [&](int c, int i, int j) -> int{
//        if(c == 0){
//            return query(i, j, m, n) ? 1 : 0;
//        }
//        int& res = memo[c][i][j];
//        if(res != -1) return res;
//        res = 0;
//        for(int j2 = j; j2 < n; ++j2){
//            if(query(i, j, m, j2)){
//                res = (res + dfs(c - 1, i, j2)) % MOD;
//            }
//        }
//        for(int i2 = i; i2 < m; ++i2){
//            if(query(i, j, i2, n)){
//                res = (res + dfs(c - 1, i2, j)) % MOD;
//            }
//        }
//        return res;
//    };
//    return dfs(k - 1, 0, 0);
    int f[k][m][n];
    for(int c = 0; c < k; ++c){
        for(int i = 0; i < m; ++i){
            for(int j = 0; j <n; ++j){
                if(c == 0){
                    f[c][i][j] = query(i, j, m, n) ? 1 : 0;
                }
                int res = 0;
                for (int j2 = j; j2 < n; ++j2) {
                    if (query(i, j, m, j2)) {
                        res = (res + f[c - 1][i][j2]) % MOD;
                    }
                }
                for (int i2 = i; i2 < m; ++i2) {
                    if (query(i, j, i2, n)) {
                        res = (res + f[c - 1][i2][j]) % MOD;
                    }
                }
                f[c][i][j] = res;
            }
        }
    }
    return f[k - 1][0][0];
}

int leetcode1444::query(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r2][c1] - sum[r1][c2] + sum[r1][c1];
}
