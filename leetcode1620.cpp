//
// Created by lzw on 2022/11/2.
//

#include "leetcode1620.h"


vector<int> leetcode1620::bestCoordinate(vector<vector<int>> &towers, int radius) {
    //只考虑 50*50 因为在50之外的可以通过对称
    int max=0;
    vector<int> ans={0,0};
    for(int i=0;i<=50;i++){
        for(int j=0;j<=50;j++){
            int power=0;
            for(vector<int> tower:towers){
                double distance=sqrt((tower[0]-i)*(tower[0]-i)+(tower[1]-j)*(tower[1]-j));
                if(distance<=radius){
                    power+=tower[2]/(1+distance);
                }
            }
            if(power>max){
                max=power;
                ans={i,j};
            }else if(power==max){
                ans=min(ans,{i,j});
            }
        }
    }
    return ans;
}