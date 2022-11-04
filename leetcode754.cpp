//
// Created by lzw on 2022/11/4.
//

#include "leetcode754.h"
//数学。找到第一个使 sum = 1 + 2 + ... + k >= target 且 sum - target 为偶数的 k。
//
//首先，可以将所有 target 为负的情况转化为 target 为正的情况。
//
//我们一直向右走，直到所处的位置超过 target，此时处在 sum = 1 + 2 + ... + k。我们可以算出多走了几个位置：a = sum - target。那么我们就要使前面走的某一步 x 反向，
// 使 sum 变为：sum' = sum - a = target = 1 + 2 + ... - x + ... + k。可以看到，sum' 其实是在 sum 的基础上减了 2 个 x：sum' = sum - 2x。
//
//那么就可以推出 a = 2x = sum - target。所以 sum - target 必须为偶数。
//
//所以我们只需要找到第一个使 sum = 1 + 2 + ... + k >= target 且 sum - target 为偶数的 k 即为答案。

int leetcode754::reachNumber(int target) {
    target=(target>0?target:-target);
    //先都往前走，走不了了就往后往前 每次加1.
    int i=1;
    //根据前n项和找到第一次大于target的i
    int sum=0;
    while(true){
        sum+=i;
        if(sum>=target && (sum-target)%2==0){
            return i;
        }
        i++;
    }
    return -1;

}