//
// Created by 25467 on 2023/9/14.
//

#include "leetcode1222.h"

std::vector<std::vector<int>>
leetcode1222::queensAttacktheKing(std::vector<std::vector<int>> &queens, std::vector<int> &king) {
    //store the queen pos;
    int queen[8][8] = {0};
    for(const auto& q : queens){
        queen[q[0]][q[1]] = 1;
    }
    //8 * 8, from king and 8 dir;
    std::vector<std::vector<int>> res;
    int dir[8] = {0};
    int cur_x = king[0], cur_y = king[1];
    for(int step = 0; step < 8; ++step){
        for(int i =0; i < 8; ++i){
            //如果这个方向已经有了
            if(dir[i] == 1){
                continue;
            }
            int new_x = cur_x + x_dir[i] * (step + 1);
            int new_y = cur_y + y_dir[i] * (step + 1);
            if(new_x < 0 || new_x >= 8 || new_y < 0 || new_y >=8){
                continue;
            }
            if(queen[new_x][new_y] == 1){
                res.push_back({new_x, new_y});
                dir[i] = 1;
            }
        }
    }
    return res;
}
