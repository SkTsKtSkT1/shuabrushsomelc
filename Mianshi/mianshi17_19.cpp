//
// Created by lzw on 2022/9/26.
//

#include "mianshi17_19.h"
#include "iostream"
vector<int> mianshi17_19::missingTwo(vector<int> &nums) {
    return xorCal(nums);
}

vector<int> mianshi17_19::addSum(vector<int> &nums) {
//使用等差数列求解，先求一个 再求一个
    int sumNums=0;
    for(int i:nums){
        sumNums+=i;
    }
    int n=nums.size()+2;//缺失两个
    int sumTwo=(n+1)*n/2-sumNums;//等差数列求和得到两数之和
    int divideNum=sumTwo/2; //两个数不相等，所以和的一半是分解
    sumNums=0;
    for(int i:nums){
        if(i<=divideNum){ //累和
            sumNums+=i;
        }
    }
    int One=(divideNum+1)*divideNum/2-sumNums;
    return vector<int>{One,sumTwo-One};

}

vector<int> mianshi17_19::hashTab(vector<int> &nums) {
    for(int i=0;i<3;i++){
        nums.push_back(-1); //加入三个，第一个0就默认是-1；
    }
    for(int i=0;i<nums.size();i++){
        while(nums[i]!=i && nums[i]!=-1){
            std::swap(nums[i],nums[nums[i]]);
        }
    }
    vector<int> ans;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==-1){
            ans.push_back(i);
        }
    }
    return ans;
}

vector<int> mianshi17_19::xorCal(vector<int> &nums) {
//利用位运算的性质：
//
//对于任何数 xx，都有 x \oplus x = 0x⊕x=0
//异或运算满足结合律，即 (a \oplus b) \oplus c = a \oplus (b \oplus c)(a⊕b)⊕c=a⊕(b⊕c)
//lowbitlowbit 运算获取最低一位的 11 及其后面的所有 00，公式为 lowbit(x) = x \& (-x)lowbit(x)=x&(−x)
//我们将 nums 中所有数进行异或到 xx，再将 [1,2..n][1,2..n] 的所有数也异或到 xx。得到的 xx 是两个缺失的正整数的异或和。
//
//然后我们运用 lowbitlowbit 获取最低一位的 11，那么这两个缺失的正整数在这一位上必然一个为 11，一个为 00。我们据此进行分组异或。最终得到两个缺失的正整数 aa 和 bb。
//
//作者：lcbin
//链接：https://leetcode.cn/problems/missing-two-lcci/solution/by-lcbin-jpie/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    int n=nums.size()+2;
    int xorNum=0;

    for(int i:nums){
        xorNum^=i;
    }
    for(int i=0;i<=n;i++){
        xorNum^=i;
    }
    //只会保留两个缺少的数字的异或结果
    //lowbit https://www.cnblogs.com/fusiwei/p/11752540.html
    // 可以得到最低一位的1和后面所有的0，因为两数在此必定一个为1一个为0
    int diff=xorNum&(-xorNum);
    int a=0;
    for(int i:nums){
        if(i&diff){ //如果i中diff位为1 则a与其异或
            a^=i;
        }
    }
    for(int i=0;i<=n;i++){
        if(i&diff){
            a^=i;
        }
    }
    //可以得到只出现过一次的第i位为diff的数字a，因为a^b=xorNum,那么xorNum^a=a^b^a=a^a^b=b
    int b=xorNum^a;
    return {a,b};
}

std::ostream &mianshi17_19::operator<<(const vector<int> &nums) {
    for(vector<int>::const_iterator it=nums.begin();it!=nums.end();it++){
        std::cout<<*it<<" ";
    }
    std::cout<<std::endl;
}