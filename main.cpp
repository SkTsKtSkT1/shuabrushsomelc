#include <iostream>
#include "simple/leetcode88.h"

int main(int argc, char** argv){
    leetcode88 lc88;

    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    lc88.merge(nums1, m, nums2, n);
    for(auto i : nums1){
        std::cout << i << " ";
    }
}

//int main() {
//  int k =0;
//  long n =0;
//  std::cin >> n >> k;
//  std::cout << n << " " << k << "\n";
//  std::string num;
//  std::cin >> num;
//  std::cout << num << "\n";
//  std::string res;
//  bool insert = false;
//  //从高位往低位找到第一个大于数字的地方
//  for(const char& c : num){
//      if(!insert && c <= (char)(k + '0')){
//          res += (char)(k + '0');
//          insert = true;
//      }
//      res += c;
//  }
//  long r = 0;
//  for(int i = 0; i < res.size(); ++i){
//      r = r * 10 - '0' + res[i];
//  }
//  std::cout << r;
//  return r;
//}

