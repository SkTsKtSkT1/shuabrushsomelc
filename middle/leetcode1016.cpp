//
// Created by 25467 on 2023/5/11.
//

#include <cstring>
#include "leetcode1016.h"
#include "cmath"
#include "unordered_set"
//反过来想，把 s 的子串都转成二进制数，如果数字在
//[1,n] 内，就保存到一个哈希表中。如果哈希表的大小最终为n，就说明[1,n] 的二进制都在s 里面。

//代码实现时，设当前枚举的子串对应的下标区间为[i,j]，手动把这段子串转成二进制数。这里的技巧是，设当前得到的二进制数为s[j+1] 为
//x 更新为 (x << 1) | (c - '0')，从而 O(1) 地计算出子串[i,j+1] 对应的的二进制数。
//此外，可以跳过s[i]=0 的情况。例如s=0110，从s[0] 开始和从
//s[1] 开始，得到的二进制数都是一样的。并且，由于保证从s[i]=1 开始枚举，二进制数的大小会指数增长，一旦x>n，就停止枚举j。所以对于固定的i，至多枚举O(logn) 个j。

//链接：https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/solution/san-chong-suan-fa-cong-bao-li-dao-you-hu-nmtq/


bool leetcode1016::queryString(string s, int n) {
    std::unordered_set<int> u_set;
    for (int i = 0; i < s.size(); i++) {
        int x = s[i] - '0';
        if (x == 0) continue; // 0110  从0和从1开始枚举都是可以的
        for (int j = i + 1; x <= n; j++) {
            u_set.insert(x);
            if (j == s.size()) break;
            x = (x << 1) | (s[j] - '0');
        }
    }

    return u_set.size() == n;
}


