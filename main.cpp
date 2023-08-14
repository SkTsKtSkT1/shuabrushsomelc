#include <iostream>
#include "middle/leetcode833.h"

int main(int argc, char** argv){
    leetcode833 lc833;
    std::string s = "abcd";
    std::vector<int> indexes = {0, 2};
    std::vector<std::string> sources = {"ab", "ec"};
    std::vector<std::string> targets = {"eee", "ffff"};

    std::cout << lc833.findReplaceString(s, indexes, sources, targets) << std::endl;
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

