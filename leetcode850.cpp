//
// Created by lzw on 2022/9/16.
//

#include "leetcode850.h"

int leetcode850::rectangleArea(vector<vector<int>> &rectangles) {
    int nums= rectangles.size();

    //离散化
    vector<int> edge;
    for(const vector<int>& rect:rectangles){
        //xmin
       edge.push_back(rect[0]);
       //xmax
       edge.push_back(rect[2]);
    }
    std::sort(edge.begin(), edge.end());
    long ans=0;
    //将图形分割为由n个矩形水平组成
    for(int i=1;i<edge.size();i++){
        int a=edge[i-1],b=edge[i],len=b-a;
        if(len==0) continue;
        vector<vector<int>> line;
        //遍历所有矩形，若该矩形存在面积在所给的两条线之间，则记录其y轴
        for(const vector<int>& rect:rectangles){
            if(rect[0]<=a&&b<=rect[2]){
                line.push_back(vector<int>{rect[1],rect[3]});
            }
        }
        //然后按照l[0]从小到大l[1]从小到大排序
        std::sort(line.begin(),line.end(),[&](vector<int> l1,vector<int> l2){
//            if(l1[0]==l2[0]) return l1[1]<l2[1];
//            return l1[0]<l2[0];
            //return l1[0]==l2[0]?l1[1]<l2[1]:l1[0]<l2[0];
          return l1[0]!=l2[0]?l2[0]>l1[0]:l2[1]>l1[1];
//            return l1[0]!=l2[0]?l1[0]-l2[0]:l1[1]-l2[1];
        });
        long  tot=0,l=-1,r=-1;
        for(const vector<int>& cur:line){
            if(cur[0]>r){
                tot+=r-l;
                l=cur[0];
                r=cur[1];
            }else if(cur[1]>r){
                r=cur[1];
            }
        }
        tot+=r-l;
        ans+=tot*len;
        ans%=mod;
    }
    return (int)ans;
}