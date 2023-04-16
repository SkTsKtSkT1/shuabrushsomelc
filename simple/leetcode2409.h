//
// Created by 25467 on 2023/4/17.
//

#ifndef ALGORITHM_LEETCODE2409_H
#define ALGORITHM_LEETCODE2409_H
#include "string"
using std::string;

class leetcode2409 {
public:
    int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob);
    int to_day(string time_string);
};


#endif //ALGORITHM_LEETCODE2409_H
