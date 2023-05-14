//
// Created by 25467 on 2023/5/14.
//

#include "leetcode1054.h"
#include "unordered_map"
#include "algorithm"
vector<int> leetcode1054::rearrangeBarcodes(vector<int> &barcodes) {
    std::unordered_map<int,int> u_map;
    for(int& barcode:barcodes){
        u_map[barcode]++;
    }
    std::sort(barcodes.begin(),barcodes.end(),[&](int a,int b)->bool{
        return u_map[a]>u_map[b] || (u_map[a]==u_map[b] && a<b); //如果相等，那么a<b，即小数字在前 如果不相等那么a出现次数大于b出现次数 确保相同的数相邻
    });
    vector<int> ans(barcodes.size());
    for(int k=0 ,j=0;k<2;++k){ //奇数偶数
        for(int i=k; i <ans.size();i+=2){
            ans[i]=barcodes[j++];
        }
    }
    return ans;
}
