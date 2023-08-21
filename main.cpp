#include <iostream>
#include "middle/leetcode849.h"

int main(int argc, char **argv) {
    leetcode849 lc849;
    std::vector<int> seats = {0, 1};
    std::cout << lc849.maxDistToClosest(seats) << std::endl;
    return 0;
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

