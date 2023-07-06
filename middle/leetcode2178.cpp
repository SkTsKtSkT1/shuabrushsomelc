//
// Created by 25467 on 2023/7/6.
//

#include "leetcode2178.h"
#include "cmath"
std::vector<long long> leetcode2178::maximumEvenSplit(long long int finalSum) {
    if(finalSum % 2){
        return {};
    }

    long long preLen = (long long)((-1 + sqrt(1 + 4 * finalSum)) / 2); // (2 + 2n) * n / 2 = n(n + 1) --> n^2 + n = finalSum; -> n =  -1 +/- sqrt(1^2 + 4pre)/2 * 1
    std::vector<long long> ans(preLen, finalSum - preLen * (preLen - 1));
    for(int i = ans.size() - 2; i >= 0; --i){
        ans[i] = --preLen << 1; // n-1 n-2 ...... 1 *2
    }
    return ans;
}
