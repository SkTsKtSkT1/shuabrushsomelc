//
// Created by 25467 on 2023/4/23.
//

#include <algorithm>
#include "leetcode1657.h"
//第一个，word1中出现的字符在word2中都出现。
//
//第二个，字符出现的频次数相等。比如，对于word1中字符出现次数从小到大排序为531，那么word2中字符出现的次数从小到大也必须是531。无需出现的次数对应的字符相同。
//
//满足第二个条件，利用规则2，可以将两个字符变换对应的字符出现次数相等。
//
//利用规则1，可两两交换，使得两个字符串相等。
#include "vector"
using std::vector;
bool leetcode1657::closeStrings(string word1, string word2) {
    if (word1.size()!=word2.size()){
        return false;
    }
    vector<int> w1(26,0);
    vector<int> w2(26,0);
    for(char& w:word1){
        w1[w-'a']++;
    }
    for(char& w:word2){
        w2[w-'a']++;
        if(w1[w-'a']==0){
            return false;
        }
    }

    std::sort(w1.begin(), w1.end());
    std::sort(w2.begin(), w2.end());
    return w1==w2;

}
