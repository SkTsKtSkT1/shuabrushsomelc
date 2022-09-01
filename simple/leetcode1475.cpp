//
// Created by lzw on 2022/9/1.
//

#include "leetcode1475.h"


std::vector<int> leetcode1475::finalPrices(std::vector<int>& prices) {
    int len=prices.size();
    for(int i=0;i<len;i++){
        int discount=findDiscount(prices,i);
        prices[i]-=discount;
    }
    return prices;
}

int leetcode1475::findDiscount(std::vector<int> &prices, int index) {
    int len=prices.size();
    if(index == len-1) return 0;
    for(int i=index+1;i<len;i++) {
        if (prices[i] <= prices[index])
            return prices[i];
    }
    return 0;
}

