//
// Created by skt on 2023/9/8.
//

#include "leetcode2651.h"

int leetcode2651::findDelayedArrivalTime(int arrivalTime, int delayedTime) {
    return (arrivalTime + delayedTime) % 24;
}
