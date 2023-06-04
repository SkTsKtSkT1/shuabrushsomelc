//
// Created by 25467 on 2023/6/3.
//

#include "leetcode1156.h"
#include "unordered_map"
using std::unordered_map;
using std::string;
int leetcode1156::maxRepOpt1(std::string text) {
    int n = text.size();
    unordered_map<int, int> hash; //记录每个字母出现的总次数, 判断是否可以借字母;
    for(char& c: text) hash[c]++;
    int nums[n], idx = -1;

    int res = 0;
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n && text[j] == text[i]) j++;
        nums[++idx] = j - i; //// 记录该字母连续出现的次数,找出当前连续的一段 [i, j)
        if(idx > 1 && nums[idx - 1] == 1 && i > 1 && text[i - 2] == text[i]){ //// 两个相邻的串只隔一个字母，小于总数时，合并+1;
            res = std::max(res, std::min(nums[idx] + nums[idx-2] + 1, hash[text[i]]));
        }
        res = std::max(res, std::min(nums[idx] + 1, hash[text[i]])); //// 其他情况，小于总数时，+1;
        i = j - 1;
    }
    return res;
}
