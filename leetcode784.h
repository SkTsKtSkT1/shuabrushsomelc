//
// Created by lzw on 2022/10/30.
//

#ifndef ALGORITHM_LEETCODE784_H
#define ALGORITHM_LEETCODE784_H
#include "string"
#include "vector"

using std::string;
using std::vector;

class leetcode784 {
private:
    vector<string> _ans;
public:
    vector<string> letterCasePermutation(string s);
    void dealEach(vector<string>& res, string& s,int index);
};


#endif //ALGORITHM_LEETCODE784_H
