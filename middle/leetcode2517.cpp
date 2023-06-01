//
// Created by 25467 on 2023/6/1.
//

#include "leetcode2517.h"
#include "algorithm"
#include "functional"

using std::vector;
//https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/solution/er-fen-da-an-by-endlesscheng-r418/
int leetcode2517::maximumTastiness(std::vector<int> &price, int k) {
    std::sort(price.begin(), price.end(),[&](int a, int b) -> bool{
       return a<b;
    }); //from less to more

    std::function<int(int)> f = [&](int d) -> int{
        int cnt = 1, pre = price[0];
        for(int& p:price){
            if(p >= pre + d){
                cnt++;
                pre = p;
            }
        }
        return cnt;
    }; //定义 f(d) 表示甜蜜度至少为 d 时，至多能选多少类糖果。

    int left = 0, right = (price.back()-price[0])/(k-1) + 1; //此处二分的是甜蜜度
    while(left + 1 < right){ //保证开区间存在
        int mid = left + (right - left) / 2;
        (f(mid) >= k? left: right) = mid;
    }
    return left;
}
