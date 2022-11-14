//
// Created by lzw on 2022/11/14.
//

#include "leetcode805.h"
#include "numeric"
#include "unordered_set"
bool leetcode805::splitArraySameAverage(vector<int> &nums) {
    int n=nums.size();
    if(n==1) return false;
    //float avr=sumTotal/n;
    //将nums减去avr，转换为能否找到一个子数组A，使和为0.考虑到精度问题，直接减去sunTotal,相当于
    int sumTotal=std::accumulate(nums.begin(),nums.end(),0);
    for(int& v:nums){
        v=v*n-sumTotal;
    }
    int m=n>>1; //先取一个A=B，对半分这个数组，如果使单数就B中多一个。
    std::unordered_set<int> vis;
    //https://blog.csdn.net/sugarbliss/article/details/81099340 二进制枚举
    for(int i=1;i<(1<<m);++i){//有这么多种状态,i不需要从0开始，因为A非空，i表示状态，即用二进制的01表示数组第几个选择了
        int t=0;
        for(int j=0;j<m;++j){
            if((i&(1<<j))){//判断当前i有哪几位是1 被选择了
                t+=nums[j];
            }
        }
        if(t==0) return true;
        vis.insert(t);
    }

    int rSum= std::accumulate(nums.begin()+m,nums.end(),0);
    for(int i=1;i<(1<<(n-m));++i){
        int tot=0;
        for(int j=m;j<n;++j){
            if(i&(1<<(j-m))){
                tot+=nums[j];
            }
        }
        //如果后半个数组元素子集元素之和的相反数是前半个数组子集元素之和
        //如果存在前半个数组子集元素之和是后面所有元素之和的相反数？
        //因为tot这一项是相当于在B中选取一个A1出来，与A相加得到A0满足题意
        //如果tot=rsum 那么B就是空的，但如果
        //若rsum==tot并且右半数组并没有全选，剩余右半数组和一定为0。此时若left.contains(tot)，那left除tot的剩余数组和肯定也是0，程序早就在前面返回结果了:)
        if(tot==0 || (rSum!=tot && vis.count(-tot))){
            return true;
        }
    }
    return false;
}