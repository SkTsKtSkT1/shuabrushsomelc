//
// Created by lzw on 2022/9/7.
//

#include "leetcode1592.h"


std::string leetcode1592::reorderSpaces(std::string text) {
    int len = text.size();
    int space = 0;
    int words = 0;
    //如果当前非空格且下一项为空格，则为一个单词，但考虑到以单词结尾，若最后一个非空格，也是一个单词
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') space++;
        else if (i == len - 1 || text[i + 1] == ' ') {
            words++;
        }
    }
    int between = (words == 1 ? 0 : space / (words - 1));
    int end = (words == 1 ? space : space % (words - 1));
    //循环对字符串进行修改
    std::string ans;
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ') continue;
        ans += text[i];
        //到了单词的结尾
        if (text[i + 1] == ' ' || i == text.size() - 1) {
            words--;
            if (words == 0) for (int j = 0; j < end; j++) ans += ' ';
            else
                for (int j = 0; j < between; j++) {
                    ans += ' ';
                }
        }
    }
    return ans;
}