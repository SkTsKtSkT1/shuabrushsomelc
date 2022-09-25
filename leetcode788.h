//
// Created by lzw on 2022/9/25.
//

#ifndef ALGORITHM_LEETCODE788_H
#define ALGORITHM_LEETCODE788_H


class leetcode788 {
public:
    int rotatedDigits(int n);
private:
    int rotate[10]={0,1,5,-1,-1,2,9,-1,8,6};
    bool maybeGood(int n);
};


#endif //ALGORITHM_LEETCODE788_H
