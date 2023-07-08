//
// Created by 25467 on 2023/7/8.
//

#include "leetcode167.h"

std::vector<int> leetcode167::twoSum(std::vector<int> &numbers, int target) {
    int i = 0, j = numbers.size() - 1;
    while(i < j ){
        if(numbers[i] + numbers[j] < target){
            i++;
        }else if(numbers[i] + numbers[j] > target){
            j--;
        }else if(numbers[i] + numbers[j] == target){
            return {i + 1, j + 1};
        }
    }
    return {};
}
