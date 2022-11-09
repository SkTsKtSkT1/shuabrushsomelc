//
// Created by skt on 2022/11/9.
//

#include "leetcode764.h"

int leetcode764::orderOfLargestPlusSign(int n, vector<vector<int>> &mines) {
    vector<vector<int>> dp(n,vector<int>(n,n));
    for(vector<int>& m:mines){
        dp[m[0]][m[1]]=0;
    }
    for(int k=0;k<n;k++){//K表示第k列，第k行 相当于找到四个方向连续的1的个数
        int up=0,down=0,left=0,right=0;
        for(int i=0,j=n-1;i<n;++i,--j){
            left=(dp[k][i]==0?0:left+1); //k行左边
            dp[k][i]=std::min(left,dp[k][i]);
            right=(dp[k][j]==0?0:right+1);//k行右边
            dp[k][j]=std::min(right,dp[k][j]);
            up=(dp[i][k]==0?0:up+1);//k列上边
            dp[i][k]=std::min(up,dp[i][k]);
            down=(dp[j][k]==0?0:down+1);//k列下边
            dp[j][k]=std::min(down,dp[j][k]);
        }//循环结束 相当于每个dp表示该点表示四周连续1的最大个数
    }
    int res=0;
    for(vector<int> d:dp){
        for(int di:d){
            if(di>res){
                res=di;
            }
        }
    }
    return res;
}