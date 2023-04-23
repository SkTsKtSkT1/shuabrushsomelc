//
// Created by 25467 on 2023/4/23.
//

#include "leetcode1105.h"
#include "iostream"

int leetcode1105::minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
    int n=books.size();
    vector<int> dp(n+1,1000*1000);// // dp[i(第几本书)] = 所占的最小高度
    dp[0]=0;
    for(int i=1;i<=n;i++){//既有第几层的含义又有第几本书的含义
        int w=0,h=0;
        for(int j=i;j>=1;j--){
            w+=books[j-1][0];
            if(w>shelfWidth) break;
            h=std::max(h,books[j-1][1]);
            dp[i]= std::min(dp[i],dp[j-1]+h);
        }
    }
    return dp[n];
}
