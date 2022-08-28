//
// Created by lzw on 2022/8/28.
//

#ifndef ALGORITHM_LEETCODE793_H
#define ALGORITHM_LEETCODE793_H

//x!末尾零的个数取决于分解出的2和5的个数，明显2的个数多于5，因此零的个数取决于分解出5的个数，
//分解出的个数cnt=x/f+x/f^2+......
//求等于k个数的区间段，即找到第一个f(x)=k和f(x)=k+1的位置，两者相减即为所求
//使用二分查找，左边从0开始，右边明显可以从5k开始，
//ref:https://leetcode.cn/problems/preimage-size-of-factorial-zeroes-function/solution/jie-cheng-han-shu-hou-kge-ling-by-capita-3qq1/


class leetcode793 {
public:
    int preimageSizeFZF(int k);
    int f(int x);
    long getCnt(long x);
};


#endif //ALGORITHM_LEETCODE793_H
