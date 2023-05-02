//
// Created by 25467 on 2023/5/2.
//

#include "leetcode970.h"
#include "set"
//给定三个整数 x、y和bound，返回 值小于或等于bound的所有强整数组成的列表。
//
//如果某一整数可以表示为x^i+ y^j，其中整数i >= 0 且j >= 0，那么我们认为该整数是一个强整数。
//
//你可以按 任何顺序 返回答案。在你的回答中，每个值 最多 出现一次。

vector<int> leetcode970::powerfulIntegers(int x, int y, int bound) {
    std::set<int> s; //
    vector<int> res;
    for(int a=1;a<=bound;a*=x){ //a means x^i
        for(int b=1;b<=bound-a;b*=y){ //b means y^i;
            s.insert(a+b);
            if(y==1) break;
        }
        if(x==1) break;
    }
    res.assign(s.begin(),s.end());
    return res;
}
