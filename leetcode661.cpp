//
// Created by lzw on 2022/8/25.
//

#include "leetcode661.h"


std::vector<std::vector<int>> leetcode661::imageSmoother(std::vector<std::vector<int>>& img) {
    int m=img.size();
    int n=img[0].size();
    std::vector<std::vector<int>> result(m,std::vector<int>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=0,num=0;
            for(int x=i-1;x<=i+1;x++){
                for(int y=j-1;y<=j+1;y++){
                    if(x>=0 && x<m && y>=0 && y<n){
                        sum+=img[x][y];
                        num++;
                    }
                }
            }
            result[i][j]=sum/num;
        }
    }
    return  result;
}