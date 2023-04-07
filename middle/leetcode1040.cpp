//
// Created by 25467 on 2023/4/7.
//

#include <iostream>
#include "leetcode1040.h"
#include "algorithm"
//由于我们每一次只能选择将端点石子移动到未占用且不是端点石子的位置，如果我们选择
//stones[0] 作为第一次移动的端点石子，那么从stones[0] 到 stones[1] 之间的所有未占用的位置都会被跳过，我们可以选择移动到最近的且未占用的位置，接下来每一次都将最左端的石子移动到最近的且未占用的位置，那么最多可以移动的次数为
//stones[n−1]−stones[1]+1−(n−1)；同理，如果我们选择 stones[n−1] 作为第一次移动的端点石子，那么最多可以移动的次数为 stones[n−2]−stones[0]+1−(n−1)。取两者的最大值即为最大移动次数 mx

vector<int> leetcode1040::numMovesStonesII(vector<int> &stones) {
    std::sort(stones.begin(), stones.end(),[&](int a, int b)->bool{
        return a<b;
    });
    int n=stones.size();
    //https://leetcode.cn/problems/moving-stones-until-consecutive-ii/solution/jie-ti-si-lu-by-owenzzz/
    //special condition
    int e1 =stones[n-1]-stones[1]-n+2;
    int e2=stones[n-2]-stones[0]-n+2;
    int max_move=std::max(e1, e2);

    if(e1==0 || e2==0){ //对于 1，n-1 和 0 n-2没有空位,要把连续的跳一个出来 然后多余的一个跳进去
        return {std::min(2,max_move), max_move};
    }

    int min_move=max_move;

    //滑动窗口, 枚举长度为n的窗口中最多有多少个石头，剩下的就填补
    int left=0, right=0;
    int max_cnt=0;
    for(; right<n; ++right){
        while(stones[right]-stones[left]+1 > n){// 窗口大小大于 n,最终全部石子连续等价于全部的石子最终都移动到了一个长度为 n 的窗口中
            left++; //从left 到 right之间一定要刚刚好能塞下来这么多石头
        }
        max_cnt=std::max(max_cnt, right-left+1);
    }

    return {n-max_cnt, max_move};




}


std::ostream &leetcode1040::operator<<(const vector<int> &arr) {
    for(vector<int>::const_iterator it=arr.begin(); it!=arr.end(); ++it){
        std::cout<<*(it)<<" ";
    }
    std::cout<<std::endl;
    return std::cout;
}