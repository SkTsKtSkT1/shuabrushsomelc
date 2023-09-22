//
// Created by 25467 on 2023/9/22.
//

#include "leetcode2591.h"
//我们假设有 x 个儿童获得了 8 美元，那么剩下的钱为 money−8×x，只要保证大于等于剩下的儿童数 children−x，就可以满足题意。

int leetcode2591::distMoney(int money, int children) {
    if(money < children) return -1;
    if(money > 8 * children) return children - 1;
    if(money == 8 * children - 4) return children - 2;
    //money - 8x > children - x -> money - children > 7x  -> x < delta / 7;
    return (money - children) / 7;
}
