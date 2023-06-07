//
// Created by 25467 on 2023/6/7.
//

#include "leetcode2611.h"
#include "numeric"
#include "algorithm"
//先让第二只鸭脖吃所有的奶酪( 答案累加sum(reward2) )，第一只要吃k块，那么就有第二只鸭脖吐出k块来给第一只吃
//
//吐出来的贡献怎么算，对于第i块奶酪，由于奶酪事先已经被第二只鸭脖吃过一次了，所以要吐出来就要先减reward2[i]，再加reward1[i]，把所有吐出来的奶酪价值排个序，第一只鸭脖吃最高的k块即可
int leetcode2611::miceAndCheese(std::vector<int> &reward1, std::vector<int> &reward2, int k) {
    int res = std::accumulate(reward2.begin(), reward2.end(), 0);
    //计算差值
    std::vector<int> delta(reward2.size(), 0);
    for(int i = 0;i < reward2.size(); i++){
        delta[i] = reward1[i] - reward2[i];
    }

    std::sort(delta.begin(), delta.end(), [&](int a, int b) -> bool{
        return a>b;
    });
    for(int i = 0;i < k; i++){
        res += delta[i];
    }

    return res;
}
