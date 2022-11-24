#include <iostream>
#include "leetcode795.h"

int main() {
   leetcode795 lc795;

   vector<int> nums={2,1,4,3};
   int left=2;
   int right=3;

   std::cout<<lc795.numSubarrayBoundedMax(nums,left,right);
   return 0;
}

