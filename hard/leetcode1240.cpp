//
// Created by skt on 2023/6/8.
//

#include "leetcode1240.h"
#include "iostream"
int leetcode1240::tilingRectangle(int n, int m) {
    if(m == n) return 1;
    //change input to n < m;
    if(n > m){
        std::swap(m,n);
    }
    if(m % n == 0){
        return m/n;
    }

    int mini = m*n;//全部用1*1
    //于左下角开始放大小为size的正方形
    //不同的分割方法
    //cond 1:
    for(int size = n; size >= n/2; size--){
        int delta1 = m - size;
        int delta2 = n - size;//delta2 < delta1
        int temp = 0;
        if(delta2 > 0){
            temp += tilingRectangle(delta2, size + delta1);
            temp += tilingRectangle(delta1, size);
            mini = std::min(mini, temp);
        }
        //cond 2:
        temp = 0;
        if(delta2 > 0){
            temp += tilingRectangle(delta2, size);
        }
        temp += tilingRectangle(delta1, size+delta2);
        mini = std::min(mini, temp);
        //cond3: 很奇怪啊。。。
        int delta = (delta1 - delta2) / 2;
        if(delta1 - delta == delta2 + delta &&
        delta > 0 && delta2 > 0 && size -delta >0){
            if(((size + delta) % delta2 ==0 ) || (delta2 % (size + delta) == 0)){
                if(((size - delta) %delta1 ==0) || (delta1 % (size - delta) == 0)){
                    temp = 2;
                    temp += tilingRectangle(delta2, size + delta);
                    temp += tilingRectangle(delta1, size- delta);
                    mini = std::min(mini, temp);
                }
            }
        }
    }
    return mini + 1;
}
