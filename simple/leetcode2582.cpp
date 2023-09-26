//
// Created by 25467 on 2023/9/26.
//

#include "leetcode2582.h"
//如果 time<n，枕头没有传递到队尾，传递到 time+1。
//如果 time≥n，枕头已经传递过队尾，传递到 n−(time−(n−1))=n×2−time−1。

int leetcode2582::passThePillow(int n, int time) {
    time %= (n - 1) * 2;
    if(time < n){
        return  time + 1;
    }else{
        return n - (time - (n - 1)); //time - n + 1 -> 回来了多少s
    }
}
