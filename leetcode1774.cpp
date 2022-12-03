//
// Created by lzw on 2022/12/4.
//

#include "leetcode1774.h"
#include "algorithm"

int leetcode1774::closestCost(vector<int> &baseCosts, vector<int> &toppingCosts, int target) {
    int x=*std::min_element(baseCosts.begin(), baseCosts.end());
    if(x>=target){
        return x;
    }

    vector<bool> can(target+1,false);
    int res=2*target-x;//因为最小的开销是x，那么最优范围只能在[x,2*target-x]中间
    for(int & bC:baseCosts){
        if(bC<=target){
            can[bC]=true;
        }else{
            res=std::min(res,bC);
        }
    }
    //讨论配料
    //对于每种配料 都从0-2种进行了讨论 所以是完备的
    for (int &tC: toppingCosts) {
        for (int count = 0; count < 2; count++) {
            for(int i=target;i;--i){
                if(can[i] && i+tC>target){
                    res=std::min(res,i+tC);
                }
                if(i-tC>0){
                    can[i]=can[i]|can[i-tC];//if i-tC>0,说明i-tC应该是可行的，所以i去掉配料，那个方案存在与否更新can[i]
                }
            }
        }
    }
    for(int i=0;i<=res-target;i++){
        if(can[target-i]){
            return target-i;
        }
    }
    return res;
}