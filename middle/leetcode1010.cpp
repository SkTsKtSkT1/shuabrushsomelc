//
// Created by 25467 on 2023/5/7.
//

#include "leetcode1010.h"
#include "unordered_map"
int leetcode1010::numPairsDivisibleBy60(vector<int> &time) {
    std::unordered_map<int,int> u_map;  //last time && nums
    int ans=0;
    for(int& t:time){
        //because time[i]<=500, so we examine the final is 60*18=1080 60*17=1020 60*16=960
        //Or we store the t mod 60, if t1%60+t%60=60 then t1+t % 60 =0
        ans+=u_map[(60-t%60)%60];
        u_map[t%60]++;
    }
    return ans;
}
