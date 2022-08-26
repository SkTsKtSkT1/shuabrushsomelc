//
// Created by lzw on 2022/8/25.
//

#ifndef ALGORITHM_LEETCODE658_H
#define ALGORITHM_LEETCODE658_H

#include "iostream"
#include "vector"
#include "algorithm"

//
//int main() {
//    leetcode658 lc658;
//    std::vector<int> arr={1,2,3,4,5};
//    int k=4;
//    int x=3;
//    std::vector<int> result=lc658.findClosestElements(arr,k,x);
//    for(std::vector<int>::iterator it=result.begin();it!=result.end();it++){
//        std::cout<<*it <<" "<<std::endl;
//    }
//    return 0;
//}

class leetcode658 {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x);

};


#endif //ALGORITHM_LEETCODE658_H
