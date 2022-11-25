//
// Created by lzw on 2022/11/25.
//

#ifndef ALGORITHM_LEETCODE809_H
#define ALGORITHM_LEETCODE809_H
#include "vector"
#include "string"
using std::string;
using std::vector;

class leetcode809 {
private:
    int check(const string &s,const string & word);
public:
    int expressiveWords(string s,vector<string>& words);
};


#endif //ALGORITHM_LEETCODE809_H
