#include <iostream>
#include "leetcode813.h"

int main() {
   leetcode813 lc813;

   vector<int> nums={4,1,7,5,6,2,3};
    int k=4;
   std::cout<<lc813.largestSumOfAverages(nums,k);
   return 0;
}

