//
// Created by lzw on 2022/10/29.
//

#ifndef ALGORITHM_LEETCODE1773_H
#define ALGORITHM_LEETCODE1773_H
#include "vector"
#include "string"
#include "unordered_map"

using std::vector;
using std::string;

class leetcode1773 {
private:
    std::unordered_map<string,short> mt{
            {"type",0},{"color",1},{"name",2}
    };
public:
    int countMatches(vector<vector<string>>& items,string ruleKey,string ruleValue);
};


#endif //ALGORITHM_LEETCODE1773_H
