//
// Created by 25467 on 2023/7/1.
//

#include "leetcode1.h"
#include "map"
std::vector<int> leetcode1::twoSum(std::vector<int> &nums, int target) {
    std::map<int, int> mp;//num index
    for(int i = 0; i < nums.size(); ++i){
      if(mp.count(target - nums[i])){
          return {i, mp[target - nums[i]]};
      }else{
          mp[nums[i]] = i;
      }
    }
    return {};
}
