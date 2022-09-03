//
// Created by Administrator on 2022/9/3.
//

#include "leetcode646.h"

int leetcode646::findLongestChain(std::vector<std::vector<int>>& pairs)
{
    sort(pairs.begin(), pairs.end(), cmp);
    int m = pairs.size();
    int ans = 0;
    int temp = pairs[0][1];
    for(std::vector<std::vector<int>>::iterator _=pairs.begin();_!=pairs.end();_++){
        for(std::vector<int>::iterator it=(*_).begin();it!=(*_).end();it++){
            std::cout<<*it<<" ";
        }
        std::cout<<std::endl;
    }
    for (int i = 1; i < m; i++)
    {
        if (pairs[i][0] > temp)
        {
            ans++;
            temp = pairs[i][1];
        }
    }
    return ans + 1;

}

bool leetcode646::cmp(const std::vector<int>& a, const std::vector<int>& b){
    //以结束时间最早来排序
    if(a[1]==b[1]) return a[0]<=b[0];
    return a[1]<=b[1];
}