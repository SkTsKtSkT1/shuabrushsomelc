//
// Created by 25467 on 2023/6/4.
//

#include "leetcode2465.h"
#include "set"
#include "algorithm"
using std::set;
using std::vector;
int leetcode2465::distinctAverages(std::vector<int> nums) {
    set<double> uniqueAver;

    std::sort(nums.begin(), nums.end(), [&](int a, int b) -> bool{
        return a<b; //从小到大
    });

    int i = 0, j = nums.size() - 1;
    while(i < j ){
        uniqueAver.insert(nums[i++]+nums[j--]);
    }
    return uniqueAver.size();
}
