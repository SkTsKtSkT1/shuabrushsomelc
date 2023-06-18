//
// Created by skt on 2022/9/19.
//

#include "leetcode1636.h"

vector<int> leetcode1636::frequencySort(vector<int> &nums) {
    int len=nums.size();
    //记录每个数字和其出现的次数
    std::unordered_map<int,int> count;
    for(int i=0;i<len;i++){
        count[nums[i]]++;
    }
    std::sort(nums.begin(),nums.end(),[&](int a,int b){
        if(count[a]==count[b]) return a>b;
        else return count[a]<count[b];
    });
    return nums;
}


std::ostream& leetcode1636::operator<<(vector<int> a){
    for(vector<int>::iterator _=a.begin();_!=a.end();_++){
        std::cout<<(*_)<<" ";
    }
    std::cout<<std::endl;
    return std::cout;
}