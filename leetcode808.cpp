//
// Created by lzw on 2022/11/21.
//

#include "leetcode808.h"
#include "vector"
using std::vector;
//https://leetcode.cn/problems/soup-servings/solution/by-joneli-ts7a/
double leetcode808::soupServings(int n) {
    if(n>4377){return 1;}
    //dp+全概率
    int total=n%25 ? n/25+1 :n/25;
    vector<vector<double>> dp(total+1,vector<double>(total+1,0));
    dp[0][0]=0.5; //0+1.0/2
    for(int i=1;i<=total;i++){
        dp[0][i]=1;
    }
    for(int i=1;i<=total;i++){
        for(int j=1;j<=total;j++){
            dp[i][j]=0.25*(dp[std::max(0,i-4)][j]+dp[std::max(0,i-3)][std::max(0,j-1)]+dp[std::max(0,i-2)][std::max(0,j-2)]+dp[std::max(0,i-1)][std::max(0,j-3)]);
        }
    }

    return dp[total][total];

}

double leetcode808::soupServings1(int n) {
    if(n>4377){return 1;}
    int total=n%25 ? n/25+1 :n/25;
    vector<vector<double>> dp(total+1,vector<double>(total+1,0));
    dp[total][total]=1;
    for(int i=total;i>0;--i){
        for(int j=total;j>0;--j){
            if(dp[i][j]==0) continue;
            double temp=dp[i][j]/4;
            dp[std::max(0,i-4)][j]+=temp;
            dp[std::max(0,i-3)][std::max(0,j-1)]+=temp;
            dp[std::max(0,i-2)][std::max(0,j-2)]+=temp;
            dp[std::max(0,i-1)][std::max(0,j-3)]+=temp;
        }
    }

    dp[0][0]/=2;
    for(int i=1;i<=n;i++){
        dp[0][0]+=dp[0][i];
    }
    return dp[0][0];
}

//4376
int leetcode808::findUpper(){
    int i=50;
    while(1) {
        if (soupServings(i) >  0.99999) {
            return i;
        }
        i++;
    }
}