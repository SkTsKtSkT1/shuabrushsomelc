//
// Created by 25467 on 2023/5/27.
//

#include "leetcode1093.h"
using std::vector;
std::vector<double> leetcode1093::sampleStats(std::vector<int> &count) {
    int n = count.size();
    double s = 0, cnt = 0;
    vector<double> ans(5,-1);
    ans[4] = 0;
    for(int i = 0;i < n;++i){
        if(count[i]!=0 && ans[0] == -1) ans[0]=i;
        if(count[i]!=0) ans[1]=i;
        if(count[i]>count[ans[4]]) ans[4]=i;
        s += (double) count[i]*i;
        cnt += count[i];
    }
    ans[2] = s/cnt;
    //从左边删除最多 (n-1)/2 个数
    for(int i=0, c= cnt/2+1; i<n && c>0; ++i){
        c -= count[i];
        if(c<=0) ans[3]=i;
    }
    // 从右边删除最多 (n-1)/2 个数
    for(int i=n-1, c=cnt/2+1; i>=0 && c>0; i--){
        c -= count[i];
        if(c<=0) ans[3]+=i;
    }
    // 中间两位数(可能是同一个数)求平均
    ans[3]/=2;
    return ans;

}
