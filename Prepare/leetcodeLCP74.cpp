//
// Created by 25467 on 2023/5/4.
//

#include "leetcodeLCP74.h"
#include "set"
#include "array"
#include "algorithm"
#include "string.h"
int leetcodeLCP74::fieldOfGreatestBlessing(vector<vector<int>> &forceField) {
    vector<long long> x_set,y_set; //默认从小到大
    for(vector<int>& field:forceField){
        long long i=field[0],j=field[1],side=field[2];
        x_set.push_back(2*i-side);
        x_set.push_back(2*i+side);
        y_set.push_back(2*j-side);
        y_set.push_back(2*j+side);
    }

    sort(x_set.begin(), x_set.end());
    sort(y_set.begin(),y_set.end());
    x_set.erase(std::unique(x_set.begin(), x_set.end()),x_set.end()); //该函数的作用是“去除”容器或者数组中相邻元素的重复出现的元素
    //(1) 这里的去除并非真正意义的erase，而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址。
    //(2) unique针对的是相邻元素，所以对于顺序顺序错乱的数组成员，或者容器成员，需要先进行排序，可以调用std::sort()函数
    y_set.erase(std::unique(y_set.begin(), y_set.end()),y_set.end());

    int n=x_set.size(),m=y_set.size();
    int diff[n+2][m+2];
    memset(diff,0,sizeof(diff));
    for(vector<int>& field:forceField){
        long long i=field[0],j=field[1],side=field[2];
        int r1=std::lower_bound(x_set.begin(), x_set.end(),2*i-side)-x_set.begin();
        int r2=std::lower_bound(x_set.begin(), x_set.end(),2*i+side)-x_set.begin();
        int c1=std::lower_bound(y_set.begin(), y_set.end(),2*j-side)-y_set.begin();
        int c2=std::lower_bound(y_set.begin(), y_set.end(),2*j+side)-y_set.begin();
        ++diff[r1+1][c1+1];
        --diff[r1+1][c2+2];
        --diff[r2+2][c1+1];
        ++diff[r2+2][c2+2];
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            diff[i][j]+=diff[i-1][j]+diff[i][j-1]-diff[i-1][j-1];
            ans=std::max(ans,diff[i][j]);
        }
    }
    return ans;
}
