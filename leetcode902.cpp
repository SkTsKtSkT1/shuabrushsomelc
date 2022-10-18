//
// Created by skt on 2022/10/18.
//

#include "leetcode902.h"
//dp[i]https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490779&idx=1&sn=9a07bef5a856ca34f5c18a4541a50e9c
//int leetcode902::atMostNGivenDigitSet(vector<string> &digits, int n) {
//    for(string c:digits){
//        digit.push_back(stoi(c));
//    }
//    return dp(n);
//}
//
//int leetcode902::dp(int x) {
//    vector<int> nDigit;
//    while(x!=0){
//        nDigit.push_back(x%10);
//        x/=10;
//    }
//    int n=nDigit.size(),len=digit.size(),ans=0;
//    //位数和x相同 从最高位开始讨论
//    for(int i=n-1,p=1;i>=0;i--,p++){
//        int cur=nDigit[i];
//        int l=0,r=len-1;
//        //find the bigest that leq cur;
//        while(l<r){
//            int mid=(l+r+1)>>1;
//            if(digit[mid]<=cur) l=mid;
//            else r=mid-1;
//        }
//        if(digit[r]>cur){
//            break;
//        }else if(digit[r]==cur){
//            ans+= r*int(pow(len,n-p));
//            if(i==0) ans++;
//        }else if(digit[r]<cur){
//            ans+(r+1)*int(pow(len,n-p));
//        }
//    }
//}


int leetcode902::atMostNGivenDigitSet(vector<std::string> &digits, int n) {
    vector<char> max;
    while(n!=0){
        max.push_back('0'+char(n%10));
        n/=10;
    }
    int len=max.size(),ans=0;
    int nums= digits.size();
    //位数少于len的，直接全排列,i表示位数
    for(int i=1;i<len;i++){
        ans+=int(pow(nums,i));
    }
    //位数等于len的 从最高位考虑
    for(int i=len-1;i>=0;i--){
        bool compareNext=false;//对比下一位数字，如果为false 说明后续无需讨论 已经排完了
        for(string c:digits){
            char dc=char(c[0]);
            if(dc<max[i]){
                ans+=pow(nums,i);
            }else if(dc==max[i]){
                compareNext=true;
                break;
            }
        }
        if(!compareNext) return ans;
    }
    return ++ans;

}