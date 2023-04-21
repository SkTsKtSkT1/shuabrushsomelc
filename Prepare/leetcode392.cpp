//
// Created by 25467 on 2023/4/20.
//

#include "leetcode392.h"

bool leetcode392::isSubsequence(string s, string t) {
    int ps=0;
    int pt=0;
    while(ps<s.size()&&pt<t.size()){
        if(s[ps]==t[pt]){
            ps++;
        }
        pt++;
    }
    return ps==s.size();
}
