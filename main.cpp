#include <iostream>
#include "middle/leetcode1019.h"

int main() {
    leetcode1019 lc1019;
    vector<int> input={5,5,2}; //552 //33 //[9,7,6,7,6,9]
    ListNode* head= lc1019.construct_list(input);
    lc1019<<lc1019.nextLargerNodes(head);
    return 0;
}

