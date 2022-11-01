//
// Created by lzw on 2022/11/1.
//

#include "leetcode1662.h"

bool leetcode1662::arrayStringsAreEqual(vector<std::string> &word1, vector<std::string> &word2) {
    int w1i = 0, w1j = 0;
    int w2i = 0, w2j = 0;
    while (w1i < word1.size() && w2i < word2.size()) {
        if (word1[w1i][w1j++] != word2[w2i][w2j++]) return false;
        if (w1j == word1[w1i].size()) {
            w1i++;
            w1j = 0;
        }
        if (w2j == word2[w2i].size()) {
            w2i++;
            w2j = 0;
        }
    }
    //防止因为长度不一样提前中断了，必须要比较完 此时w1i w2i都为word.size()+1
    return w1i == word1.size() && w2i == word2.size();
}