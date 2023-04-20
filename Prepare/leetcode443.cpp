//
// Created by 25467 on 2023/4/19.
//

#include "leetcode443.h"
#include "string"
//请在 修改完输入数组后 ，返回该数组的新长度
int leetcode443::compress(vector<char> &chars) {
    int n = chars.size();
    int i = 0, j = 0, k = 0;
    for (; i < n; i++) {
        chars[i] = chars[k];
        while (k < n && chars[j] == chars[k]) {
            k++;
        }
        int cnt = k - j;
        if (cnt != 1) {
            //if cnt is greater than 9;
            std::string cnt_s = std::to_string(cnt);
            for (char &c: cnt_s) {
                chars[++i] = c;
            }
        }
        j = k;

        if (k == n) break;
    }
    return i + 1;
}
