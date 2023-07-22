//
// Created by 25467 on 2023/7/22.
//

#include "leetcode860.h"
bool leetcode860::lemonadeChange(std::vector<int> &bills) {
    int five = 0, ten = 0;
    for(int& bill : bills){
        if(bill == 5){
            five++;
        }else if(bill == 10){
            five--;
            ten++;
        }else if(ten){ //20
            ten--;
            five--;
        }else{ //20
            five -= 3;
        }
        if(five < 0) return false;
    }
    return true;

}
