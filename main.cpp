#include <iostream>
#include "leetcode864.h"

int main() {
    leetcode864 lc864;
    vector<string> grid=
            {{"@.a.."}, {"###.#"}, {"b.A.B"}};
    std::cout<<lc864.shortestPathAllKeys(grid)<<std::endl;
    return 0;
}

