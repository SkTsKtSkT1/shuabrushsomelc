//
// Created by lzw on 2022/12/5.
//

#include "leetcode1687.h"
#include "iostream"
#include "queue"
//超时
//int leetcode1687::boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
//    //dp[i] 运送前i个箱子需要的最短行程
//    //dp[i]=dp[j-1]+cost(j,i),(i-maxB+1<=j<=i)
//    //cost（j,i)表示第j到第i的箱子的行程次数
//    auto cost=[&](vector<vector<int>>& boxes,int l,int r)->int{//cal 从j到i的cost，那么加上dp[j-1]就是dp[i]
//        int ans=2,port=boxes[l-1][0]; //无论如何也有两次
//        while(++l<=r){
//            if(boxes[l-1][0]==port) continue;
//            ans++;
//            port=boxes[l-1][0];
//        }
//        return ans;
//    };
//    int len=boxes.size();
//    vector<int> dp(len+1,INT_MAX);
//    dp[0]=0;
//    for(int i=1;i<=len;i++){
//        int sum=0;
//        for(int j=i;j>=1 && j>=i-maxBoxes+1;j--){ //j从i开始往前数，+1是因为从0开始的下标在dp数组种从1开始
//            sum+= boxes[j-1][1];
//            if(sum>maxWeight) break;
//            dp[i]=std::min(dp[i],dp[j-1]+cost(boxes,j,i));
//        }
//    }
//    return dp[len];
//}

int leetcode1687::boxDelivering(vector<vector<int>> &boxes, int portsCount, int maxBoxes, int maxWeight) {
    //dp[i] 运送前i个箱子需要的最短行程
    //dp[i]=dp[j-1]+cost(j,i),(i-maxB+1<=j<=i)
    //cost（j,i)表示第j到第i的箱子的行程次数
    int len=boxes.size();
    vector<int> dp(len+1,INT_MAX);
    dp[0]=0;
    std::deque<vector<int>> q;
    int dif=0,weiDif=0;
    for(int i=1;i<=len;i++){
        int cur=dp[i-1]+2; //cur为每次滑动窗口增加的值即dp[i-1]+cost[i,i]
        dif+= (i>=2&&boxes[i-1][0]!=boxes[i-2][0])?1:0; //若前一个箱子i-1i−1于当前箱子ii的码头相同，那么并不会增加运输次数，那么这次的dif为0，否则就会增加1
        weiDif+=boxes[i-1][1];
        while(!q.empty() && q.back()[1]+dif>=cur) q.pop_back();
        q.push_back({i,cur-dif,boxes[i-1][1]-weiDif});//存储的相对次数
        while(q.front()[0]<=i-maxBoxes || q.front()[2]+weiDif>maxWeight) q.pop_front();
        dp[i]=q.front()[1]+dif;
    }
    return dp[len];
}
