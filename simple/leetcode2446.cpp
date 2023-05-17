//
// Created by 25467 on 2023/5/17.
//

#include "leetcode2446.h"

int leetcode2446::time_trans_to_int(string time_stamp) {
    int hour = 0;
    int minu=0;
    for(int i = 0;i < 2;i++){
        hour = hour*10 + time_stamp[i]-'0';
        minu = minu*10 +time_stamp[i+3]-'0';
    }
    return hour*60+minu;
}

bool leetcode2446::haveConflict(vector<string> &event1, vector<string> &event2) {
    int start1 = time_trans_to_int(event1[0]), end1 = time_trans_to_int(event1[1]);
    int start2 = time_trans_to_int(event2[0]), end2 = time_trans_to_int(event2[1]);
    if((start1 <=start2 && end1>=end2)||(start2 <=start1 && end2>=end1)) return true;
    int start = std::max(start1, start2);
    int end = std::min(end1, end2);
    return start<=end;

}
