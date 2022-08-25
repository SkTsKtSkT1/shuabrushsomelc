//
// Created by lzw on 2022/8/23.
//

#ifndef ALGORITHM_LEETCODE47_H
#define ALGORITHM_LEETCODE47_H
#include "iostream"
#include "vector"
#include "algorithm"

//int main() {
//    leetcode47 lc47;
//    std::vector<int> nums = {1, 2, 3};
//    std::vector<std::vector<int>> result = lc47.permuteUnique(nums);
//    for (std::vector<std::vector<int>>::iterator it = result.begin(); it != result.end(); it++) {
//        for (std::vector<int>::iterator it1 = it->begin(); it1 != it->end(); it1++) {
//            std::cout << *it1;
//        }
//        std::cout << std::endl;
//    }
//    return 0;
//}

class leetcode47 {
public:
    std::vector<std::vector<int>> result;
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums);

    void dfs(std::vector<int> nums,std::vector<int> path,std::vector<bool> used);
};


#endif //ALGORITHM_LEETCODE47_H
