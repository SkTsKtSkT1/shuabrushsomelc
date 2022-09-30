//
// Created by skt on 2022/10/1.
//

#ifndef ALGORITHM_LEETCODE1694_H
#define ALGORITHM_LEETCODE1694_H
#include "string"
using std::string;

class leetcode1694 {
public:
    string reformatNumber(string number);
    string reformatNumber1(string number);
private:
    string lessThan4(string& number,int index,int nNum);
};


#endif //ALGORITHM_LEETCODE1694_H
