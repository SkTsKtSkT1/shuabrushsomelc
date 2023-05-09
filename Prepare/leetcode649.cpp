//
// Created by 25467 on 2023/5/9.
//

#include "leetcode649.h"

string leetcode649::predictPartyVictory(string senate) {
    bool R=true, D= true;
    //就是用一个变量记录当前参议员之前有几个敌对对手了，进而判断自己是否被消灭了。这个变量我用flag来表示。
    // 当flag大于0时，R在D前出现，R可以消灭D。当flag小于0时，D在R前出现，D可以消灭R
    int flag=0;
    while(R&&D){
        R=false;
        D=false;
        for(int i=0; i<senate.size();i++){
            if(senate[i]=='R'){
                if(flag < 0){
                    senate[i]=0;
                }
                else R=true;
                flag++;
            }
            if(senate[i]=='D'){
                if(flag>0){
                    senate[i]=0;
                }else
                    D=true;
                flag--;
            }
        }
    }
    return R?"Radiant":"Dire";
}
