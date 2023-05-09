//
// Created by 25467 on 2023/5/9.
//

#include "leetcode2437.h"

int leetcode2437::countTime(string time) {
    int t[5]={0};
    for(int i=0;i<time.size();i++){
        t[i] = isdigit(time[i])?time[i]-'0':-1;
    }
    int time_hour=1,time_minu=1;
    if(t[0]==-1 || t[1]==-1){
        if(t[1]!=-1){ //means ?x
            time_hour = t[1]<4?3:2;
        }else if(t[0]!=-1){ //x?
            time_hour = t[0]==2?4:10;
        }else{
            time_hour = 24;
        }
    }
    if(t[3]==-1 || t[4]==-1){
        if(t[4]!=-1){ // ?x
            time_minu = 6;
        }else if(t[3]!=-1){
            time_minu= 10;
        }else{
            time_minu=60;
        }
    }
    return time_hour*time_minu;
}
