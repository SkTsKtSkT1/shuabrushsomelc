#include <iostream>
#include "Prepare/leetcode443.h"

int main() {
    leetcode443 lc443;
    vector<char> chars = {'a', 'a', 'a', 'b', 'b', 'a', 'a'};
    std::cout << lc443.compress(chars);

    return 0;
}

