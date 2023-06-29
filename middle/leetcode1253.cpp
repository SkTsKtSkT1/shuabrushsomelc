//
// Created by 25467 on 2023/6/29.
//

#include "leetcode1253.h"

std::vector<std::vector<int>> leetcode1253::reconstructMatrix(int upper, int lower, std::vector<int> &colsum) {
    int n = colsum.size();
    std::vector<std::vector<int>> ans(2, std::vector<int>(n, 0));
    for(int i = 0; i < colsum.size(); i++){
        if(colsum[i] == 2){
            ans[0][i] = 1;
            ans[1][i] = 1;
            --upper;
            --lower;
        }else if(colsum[i] == 1){
            if(upper > lower){
                ans[0][i] = 1;
                --upper;
            }else{
                ans[1][i] = 1;
                --lower;
            }
        }
        if(upper < 0 || lower < 0){
            break;
        }
    }
    return lower || upper ? std::vector<std::vector<int>> () : ans;

}
