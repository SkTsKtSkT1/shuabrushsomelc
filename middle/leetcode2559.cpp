//
// Created by 25467 on 2023/6/2.
//

#include "leetcode2559.h"
using std::vector;
using std::string;

std::vector<int> leetcode2559::vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries) {
    int n = words.size();
    int s[n+1];
    s[0] = 0;
    for(int i = 0; i < n; i++){
        string w = words[i];
        int m = w.size();
        s[i+1] = s[i] + (isIn(w[0]) && isIn(w[m-1]));
    }
    vector<int> v;
    for(vector<int>& q:queries){
        v.emplace_back(s[q[1] + 1] - s[q[0]]);
    }
    return v;
}

bool leetcode2559::isIn(char &c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
