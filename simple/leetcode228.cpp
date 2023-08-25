//
// Created by skt on 2023/8/26.
//

#include "leetcode228.h"

std::vector<std::string> leetcode228::summaryRanges(std::vector<int> &nums) {
    std::vector<std::string> res;
    if(nums.size() == 0){
        return res;
    }
    if(nums.size() == 1){
        res.push_back(std::to_string(nums[0]));
        return res;
    }
    int begin = 0, end = 0;
    for(int i = 1; i < nums.size(); ++i){
        if(nums[i] != nums[i - 1] + 1){
            end = i - 1;
            if(end == begin){
                res.push_back(std::to_string(nums[begin]));
            }else{
                res.push_back(std::string(std::to_string(nums[begin]) + "->" + std::to_string(nums[end])));
            }
            begin = i;
        }
    }
    if(begin == nums.size() - 1){
        res.push_back(std::to_string(nums[begin]));
    }else{
        res.push_back(std::string(std::to_string(nums[begin]) + "->" + std::to_string(nums[nums.size() - 1])));
    }


    return res;
//    //双指针
//    std::vector<std::string> res;
//    int left = 0, right = 0;
//    for(int i = 1; i < nums.size(); ++i){
//        if(nums[i] == nums[i - 1] + 1){
//            ++right;
//        }else{
//            if(left == right){
//                res.push_back(std::to_string(nums[left]));
//            }else{
//                res.push_back(std::string(std::to_string(nums[left]) + "->" + std::to_string(nums[right])));
//            }
//            left = right = i;
//        }
//    }
//    if(left == right){
//        res.push_back(std::to_string(nums[left]));
//    }else{
//        res.push_back(std::string(std::to_string(nums[left]) + "->" + std::to_string(nums[right])));
//    }
//    return res;
//    std::vector<std::string> res;
//    if(nums.size() == 0){
//        return res;
//    }
//    if(nums.size() == 1){
//        res.push_back(std::to_string(nums[0]));
//        return res;
//    }
//    int begin = 0, end = 0;
//    for(int i = 1; i < nums.size();){
//        if(nums[i] - nums[begin] != i - begin){
//            end = i - 1;
//            if(end == begin){
//                res.push_back(std::to_string(nums[begin]));
//            }else{
//                res.push_back(std::string(std::to_string(nums[begin]) + "->" + std::to_string(nums[end])));
//            }
//            begin = i;
//        }else{
//            ++i;
//        }
//    }
//    if(begin == nums.size() - 1){
//        res.push_back(std::to_string(nums[begin]));
//    }else{
//        res.push_back(std::string(std::to_string(nums[begin]) + "->" + std::to_string(nums[nums.size() - 1])));
//    }
//
//
//    return res;
}
