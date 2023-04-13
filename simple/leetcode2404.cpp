//
// Created by 25467 on 2023/4/13.
//

#include "leetcode2404.h"
#include "map"
using std::vector;
using std::map;
int leetcode2404::mostFrequentEven(std::vector<int> &nums) {
    int res=-1;
    int cnt=0;
    map<int,int> m;
    for(int& num:nums){
        if(num%2==0) {
            m[num]++;
            if(m[num]>cnt){
                cnt=m[num];
                res=num;
            }else if(m[num]==cnt){
                res=std::min(num,res);
            }
        }
    }
    return res;
}
