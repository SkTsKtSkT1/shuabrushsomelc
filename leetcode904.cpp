//
// Created by skt on 2022/10/17.
//

#include "leetcode904.h"

int leetcode904::totalFruit(vector<int> &fruits) {
    //找到只包含两种数字的最大长度
    int ans=0;
    int left=0,right=0;
    int lf=fruits[left],rf=fruits[right]; //基准种类
    while(right<fruits.size()){
        //向右滑动，并且只有两种数字（因为right从0开始
        if(fruits[right]==lf || fruits[right]==rf){
            ans=std::max(ans,right-left+1);
            right++;
        }else{
            left=right-1;
            lf=fruits[left];
            while(left>0 && fruits[left-1]==lf) left--; //找到最左
            rf=fruits[right];
            ans=std::max(ans,right-left+1);
        }
    }

    return  ans;

}