//
// Created by lzw on 2022/8/25.
//

#ifndef ALGORITHM_LEETCODE661_H
#define ALGORITHM_LEETCODE661_H
#include "iostream"
#include "vector"

//
//int main() {
//    leetcode661 lc661;
//    std::vector<std::vector<int>> img= {
//            {2,  3,  4},
//            {5,  6,  7},
//            {8,  9,  10},
//            {11, 12, 13},
//            {14,15,16}
//    };
//    std::vector<std::vector<int>> result;
//    result=lc661.imageSmoother(img);
//    for(std::vector<std::vector<int>>::iterator it=result.begin();it!=result.end();it++){
//        for(std::vector<int>::iterator it1=it->begin();it1!=it->end();it1++){
//            std::cout<<*it1<<"  ";
//        }
//        std::cout<<std::endl;
//    }
//    return 0;
//}

class leetcode661 {
public:
    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img);
};


#endif //ALGORITHM_LEETCODE661_H
