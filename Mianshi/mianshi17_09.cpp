//
// Created by lzw on 2022/9/28.
//

#include "mianshi17_09.h"
#include "algorithm"
#include "vector"
using std::vector;

int mianshi17_09::getKthMagicNumber(int k) {
    vector<int> dp(k,0);
    if(k==1) return 1;
    dp[0]=1;
    int index3=0;
    int index5=0;
    int index7=0;
    for(int i=1;i<k;i++){
        dp[i]=std::min<int>({dp[index3]*3,dp[index5]*5,dp[index7]*7});
        if(dp[i]==dp[index3]*3){
            index3++;
        }
        if(dp[i]==dp[index5]*5){
            index5++;
        }
        if(dp[i]==dp[index7]*7){
            index7++;
        }
    }
    return dp[k-1];
}