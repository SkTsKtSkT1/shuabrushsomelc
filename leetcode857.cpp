//
// Created by lzw on 2022/9/11.
//

#include "leetcode857.h"

//我们可以将quality[i]视为每个工人的劳动，而wage[i]/quality[i]视为一单位劳动的价格。这样，就可以理解为：按照所有工人中最贵的价格，
// 向每个工人按劳支付工资。那么，要使总花费最少，就要从两个方面入手：尽可能选用单位价格低的工人，以及使k个工人总劳动量尽量少。

//https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/solution/ji-yao-jie-ge-di-you-yao-shu-liang-shao-r0lj9/
double leetcode857::mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
//    vector<int> flag;
//    int len=quality.size();
//    for(int i=0;i<len;i++) flag.push_back(i); //按性价比升序排列
    int len=quality.size();
    vector<int> flag(len,0);
    std::iota(flag.begin(), flag.end(),0);//0,...n-1;
    //wa/qb<wb/qb; 单位劳动价格升序
    std::sort(flag.begin(),flag.end(),[&](int a,int b){return wage[a]*quality[b]<wage[b]*quality[a];});
    //选取单位劳动价格低的，并且quality也低的
    priority_queue<int> pq;
    double price,cnt=0,ans=INT_MAX;
    for(int i=0;i<len;i++){
        if(pq.size()<k){//这样最后添加的是最贵的单价的工人
            cnt+=quality[flag[i]];
            price=wage[flag[i]]*1.0/quality[flag[i]];
            pq.push(quality[flag[i]]);
        }else if(quality[flag[i]]<pq.top()){//之后单价只会更贵，但是如果能减少quality 也有可能最优
            cnt-=pq.top()-quality[flag[i]];//- (-)=- +
            price=wage[flag[i]]*1.0/quality[flag[i]]; //计算工资以最小的标准给
            pq.pop();
            pq.push(quality[flag[i]]);
        }
        if(pq.size()==k) {
            ans = std::min(ans, price * cnt);
        }
    }
    return ans;
}