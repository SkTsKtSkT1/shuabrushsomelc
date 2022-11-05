#include <iostream>
#include "leetcode1106.h"

int main() {
    leetcode1106 lc1106;
    string expression="|(&(t,f,t),!(t))";
    std::cout<<lc1106.parseBoolExpr(expression)<<std::endl;

    return 0;
}

