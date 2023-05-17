#include <iostream>
#include "simple/leetcode2446.h"

int main() {
    leetcode2446 lc2446;
    vector<string> event1={"01:37","14:20"};
    vector<string> event2={"05:06","06:17"};
    lc2446.haveConflict(event1,event2);
    return 0;
}

