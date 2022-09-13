#include <iostream>

#include "leetcode670.h"

int main() {
    leetcode670 lc670;
    int num=0;
    while(num!=-1){
        std::cin>>num;
        std::cout<<lc670.maximumSwap(num)<<std::endl;
    }
    return 0;
}

