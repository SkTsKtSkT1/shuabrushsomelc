#include <iostream>
#include "leetcode777.h"


int main() {
    leetcode777 lc777;
    string start="RXXLRXRXL";
    string end="XRLXXRRLX";
    std::cout<<lc777.canTransform(start,end)<<std::endl;
    return 0;
}

