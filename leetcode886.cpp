//
// Created by lzw on 2022/10/16.
//

#include "leetcode886.h"


//bool leetcode886::possibelBipartitin(int n, vector<vector<int>> &dislikes) {
//    std::set<int> par1;
//    std::set<int> par2;
//    //par1 par2一定相同大小
//    //首先按照首位和第二位从小到大排序，直接分到两类 如果出现了矛盾则return false;
//    //由于ai一定小于bi那么排序后1考虑完了就不会存在1的情况。。。
//    std::sort(dislikes.begin(), dislikes.end(),[&](vector<int> a,vector<int> b)->bool{
//        if(a[0]==b[0]) return a[1]<b[1];
//        return a[0]<b[0];
//    });
//
//    for(vector<int> d:dislikes){
//        if(!par1.count(d[0])){
//            //d0 放哪
//            if(!par2.count(d[0]) && par2.count(d[1])){
//                if(par1.count(d[1])) return false;
//                par1.insert(d[0]);
//            }else if(!par2.count(d[0]) && par1.count(d[1])) {
//                if
//                par2.insert(d[0]);
//            }
//
//        }
//        if(!par2.count(d[0])) {
//
//        }
//        if(par1.count(d[0])){
//            if(par1.count(d[1])){
//                return false;
//            }
//            if(!par2.count(d[1])){
//                par2.insert(d[1]);
//            }
//            continue;
//        }
//        if(par2.count(d[0])){
//            if(par2.count(d[1])){
//                return false;
//            }
//            if(!par1.count(d[1])){
//                par1.insert(d[1]);
//            }
//            continue;
//        }
//    }
//    return true;
//}

bool leetcode886::possibelBipartitin(int n, vector<vector<int>> &dislikes) {
    vector<vector<int>> disMat(n,vector<int>(n,0)); //n\times n matrix
    for(vector<int> d:dislikes){
        //index 和第i个
        disMat[d[0]-1][d[1]-1]=1;
        disMat[d[1]-1][d[0]-1]=1;
    }
    vector<int> par(n,0); //partition matrix use 1 and -1 to record
    for(int i=0;i<n;i++){
        if(par[i]==0&&!dfs(disMat,par,i,1,n)) return false; //如果还没有分组,并且没办法分组
    }
    return true;
}

bool leetcode886::dfs(vector<vector<int>>& disMat,vector<int>& par,int index,int group,int n){
    par[index]=group;
    for(int i=0;i<n;i++){
        if(i==index) continue;
        if(disMat[index][i]== 1 && par[i]==group) return false;//如果index相斥且属于同一个组，则false;
        //如果没分组，但是此处是相斥且不能分给另一个组 当然也是false;
        if(disMat[index][i]==1 && par[i]==0 && !dfs(disMat,par,i,group*-1,n)) return false;
    }
    return true;
}