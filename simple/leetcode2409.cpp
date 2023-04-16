//
// Created by 25467 on 2023/4/17.
//

#include "leetcode2409.h"

int leetcode2409::countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

    int ans=std::min(to_day(leaveAlice),to_day(leaveBob))-std::max(to_day(arriveBob),to_day(arriveAlice))+1;
    return  ans>0?ans:0;
}

int leetcode2409::to_day(string time_string) {
    int month=0;
    int day=0;
    month= std::stoi(time_string.substr(0,2));
    day = std::stoi(time_string.substr(4));
    for(int i=0; i<month-1;++i){
        day+=days[i];
    }

    return day;
}
