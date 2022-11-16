#include <iostream>
#include "leetcode792.h"

int main() {
    leetcode792 lc792;
    vector<string> words={"a","bb","acd","ace"};
    string s="abcde";
    std::cout<<lc792.numMatchingSubseq(s,words)<<std::endl;
    return 0;
}

