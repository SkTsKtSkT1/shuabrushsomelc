//
// Created by 25467 on 2023/5/4.
//

#include "leetcode2106.h"
#include "algorithm"
//使用$fruit$数组预处理一个前缀和数组$f$，$f[i]$代表位置从$0$走到$i$能拿到多少个果子，由题可知$i$满足$0\leq i\leq 200000$，所以$f$大小开$200001$即可。
//
//我们想的的走法无非是两种：
//
//先向右走$x$步，再折回来向左走$y$步；
//先向左走$x$步，再折回来向右走$y$步。
//这两种走法都走了$2*x+y$步。
//
//如此，我们可以枚举$x$，根据$k$算出$y$，然后用前缀和数组计算出本次拿到的果子数并取max即可。
int leetcode2106::maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int f[200001]={0};
    for(vector<int>& fruit:fruits){
        f[fruit[0]]+=fruit[1];
    }
    for(int i=1;i<=2e5;++i){
        f[i]+=f[i-1];
    }
    int ans=0;
    for(int x=0;2*x<=k;x++){
        int y=k-2*x;
        //先向右走$y$步，再折回来向左走$x$步；
        int l1=std::max(startPos-x,0);
        int r1=std::min(startPos+y,200000);
        //先向右走$x$步，再折回来向左走$y$步；
        int l2=std::max(startPos-y,0);
        int r2=std::min(startPos+x,200000);
        ans=std::max<int>({ans, f[r1] - (l1 ? f[l1 - 1] : 0), f[r2] - (l2 ? f[l2 - 1] : 0)});
    }
    return ans;
}
