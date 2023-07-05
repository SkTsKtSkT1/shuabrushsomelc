//
// Created by 25467 on 2023/7/5.
//

#include "leetcode2600.h"

int leetcode2600::kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    if(k <= numOnes){
        return k;
    }else if(k > numOnes && (k - numOnes) <= numZeros){
        return numOnes;
    }else{
        return 2 * numOnes - k + numZeros;
    }
    return -1;
}
