//
// Created by skt on 2022/10/21.
//

#include "leetcode901.h"
#include "math.h"
//单调栈
StockSpanner::StockSpanner() {
    this->index=-1;
    this->priceAndWeight.emplace(-1,INT_MAX);
}

int StockSpanner::next(int price) {
    index++;
    while(price>=priceAndWeight.top().second){
        priceAndWeight.pop();
    }
    int firstBig=priceAndWeight.top().first;
    int ret=index-firstBig; //index表示天数（从0开始）因此知道比其大的是第几天就可以知道ret是多少
    priceAndWeight.emplace(index,price); //然后存入这个信息
    return ret;
}