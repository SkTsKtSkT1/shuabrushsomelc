//
// Created by lzw on 2022/9/9.
//

#ifndef ALGORITHM_LEETCODE2389_H
#define ALGORITHM_LEETCODE2389_H
#include "vector"
#include "ostream"
using std::vector;
class leetcode2389 {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries);
    int bisectRight(vector<int>& nums,int q);
    std::ostream& operator<<(const vector<int>&nums);
};


#endif //ALGORITHM_LEETCODE2389_H
