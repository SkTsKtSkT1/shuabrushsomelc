#include <iostream>
#include "leetcode811.h"


int main() {
    leetcode811 lc811;
    vector<string> cpdomains={"9001 discuss.leetcode.com"};
    vector<string>ans=lc811.subdomainVisits(cpdomains);
    std::cout<<std::endl;
    return 0;
}

