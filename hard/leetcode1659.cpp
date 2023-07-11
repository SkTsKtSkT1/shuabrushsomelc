//
// Created by 25467 on 2023/6/24.
//

#include "leetcode1659.h"
#include "cmath"
#include "cstring"
#include "algorithm"
//detail:https://leetcode.cn/problems/maximize-grid-happiness/solutions/692722/1659-cchao-xiang-xi-bao-hui-de-dong-tai-9ctdj/
int leetcode1659::getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
    int differTable[3][3] = {0, 0 , 0, 0, -60, -10, 0, -10, 40};

    int maxStatus = std::pow(3, n);
    int maxStatus1 = std::pow(3, n - 1);

    int mn = m * n;
    int d[mn + 1][introvertsCount + 1][extrovertsCount + 1][maxStatus];
    memset(d, 0, sizeof(d));
    for(int xy = mn -1; xy >=0; --xy){
        int x = xy / n;
        int y = xy % n;
        for(int i = 0; i <= introvertsCount; ++i){
            for(int j = 0; j <= extrovertsCount; ++j){
                for(int status = 0; status < maxStatus; ++status){
                    int statusLeft = (status * 3) % maxStatus;
                    d[xy][i][j][status] = std::max(d[xy][i][j][status], d[xy + 1][i][j][statusLeft]);
                    if(i > 0){
                        int diff = 120 + (y != 0) * differTable[1][status % 3] + differTable[1][status / maxStatus1];
                        d[xy][i][j][status] = std::max(d[xy][i][j][status], diff + d[xy + 1][i - 1][j][statusLeft + 1]);
                    }
                    if(j > 0){
                        int diff = 40 + (y != 0) * differTable[2][status % 3] + (x > 0) * differTable[2][status / maxStatus1];
                        d[xy][i][j][status] = std::max(d[xy][i][j][status], diff + d[xy + 1][i][j - 1][statusLeft + 2]);
                    }
                }
            }
        }
    }

    return d[0][introvertsCount][extrovertsCount][0];
}
