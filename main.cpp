#include <iostream>
#include <vector>
#include "leetcode1471.h"

int main() {
    leetcode1471 lc1471;
    std::vector<int> nums={1,1,3,5,5};
    std::vector<int> ans=lc1471.getStrongest(nums,2);
    for(std::vector<int>::iterator _=ans.begin();_!=ans.end();_++){
        std::cout<<*_<<" ";
    }
    return 0;
}

