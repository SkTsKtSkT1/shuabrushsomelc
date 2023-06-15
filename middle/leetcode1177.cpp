//
// Created by 25467 on 2023/6/15.
//

#include "leetcode1177.h"
#include "array"
//如果有奇数个 a，多出的一个 a 要单独拿出来讨论：
//假如只有 a 出现奇数次，其它字母都出现偶数次。此时字符串的长度一定是奇数，那么可以把多出的这个 a 放在字符串的中心，我们仍然可以得到一个回文串，无需替换任何字母。
//如果有两种字母出现奇数次（假设是字母 a,b），由于多出的一个 a 和一个 b 无法组成回文串，可以把一个
//b 改成 a（或者把一个 a 改成 b），这样 a 和 b 就都出现偶数次了。
//如果有三种字母出现奇数次（假设是字母 a,b,c），把一个 b 改成 c，就转换成只有 a 出现奇数次的情况了。
//一般地，如果有 m 种字母出现奇数次，只需修改其中
// ⌋ 个字母。换句话说，如果第 i 次询问有 [m / 2] <= k 那么 answer[i] 为真，反之为假。
//链接：https://leetcode.cn/problems/can-make-palindrome-from-substring/solution/yi-bu-bu-you-hua-cong-qian-zhui-he-dao-q-yh5p/

std::vector<bool> leetcode1177::canMakePaliQueries(std::string s, std::vector<std::vector<int>> &queries) {
    int n = s.size(), q = queries.size();
    std::vector<std::array<int, 26>> sum(n + 1);
    for(int i = 0; i < n; i++){
        sum[i + 1] = sum [i]; //sum[i + 1][j]表示从 s[0] 到 s[i] 中，字母表的第 j 个小写字母的出现次数
        sum[i + 1][s[i] - 'a']++;
    }

    std::vector<bool> ans(q);
    for(int i = 0; i < q; i++){
        auto& query = queries[i];
        int left = query[0], right = query[1], k = query[2], m = 0;
        for(int j = 0; j < 26; j++){
            m += (sum[right + 1][j] - sum[left][j])%2;
        }
        ans[i] = m/2 <=k;
    }
    return ans;
}
