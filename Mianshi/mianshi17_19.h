//
// Created by lzw on 2022/9/26.
//

#ifndef ALGORITHM_MIANSHI17_19_H
#define ALGORITHM_MIANSHI17_19_H
#include "vector"
#include "ostream"
using std::vector;

class mianshi17_19 {
public:
    vector<int> missingTwo(vector<int>& nums);
    std::ostream& operator<<(const vector<int>& nums);
private:
    vector<int> xorCal(vector<int>& nums);
    vector<int> addSum(vector<int>& nums);
    vector<int> hashTab(vector<int>& nums);

};


#endif //ALGORITHM_MIANSHI17_19_H
