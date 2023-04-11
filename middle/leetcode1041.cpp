//
// Created by 25467 on 2023/4/11.
//

#include "leetcode1041.h"
//机器人最初位于 (0, 0) 处，面朝北方
//北方向 是y轴的正方向。
//南方向 是y轴的负方向。
//东方向 是x轴的正方向。
//西方向 是x轴的负方向。
// 1,初始方向向上
// 2.一轮指令后，方向可能不变，也可能变
// 3.方向发生变化，最多四次迭代就能变回初始方向，而且一定能变回初始方向。
// 4.不管是第一轮指定还是第N轮指定以后，第一次达到同方向，看这次的位置是不是(0,0)，如果是，则困于循环。如果不是，则不会困住
bool leetcode1041::isRobotBounded(std::string instructions) {
    int cur_x=0;
    int cur_y=0;
    int cur_direction = 0;  //N:0 E:1 S:2 W:3

    while(true){
        for (char &i: instructions) {
            if (i == 'R') {
                cur_direction = (cur_direction + 1 + 4) % 4;
            } else if (i == 'L') {
                cur_direction = (cur_direction - 1 + 4) % 4;
            } else {
                if (cur_direction == 0) {
                    cur_y += 1;
                } else if (cur_direction == 1) {
                    cur_x += 1;
                } else if (cur_direction == 2) {
                    cur_y -= 1;
                } else if (cur_direction == 3) {
                    cur_x -= 1;
                }
            }
        }
        if (cur_direction == 0 ) {
            break;
        }
    }
    return cur_x==0 && cur_y==0;
}