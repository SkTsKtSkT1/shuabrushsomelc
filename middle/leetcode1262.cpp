//
// Created by 25467 on 2023/6/19.
//

#include "leetcode1262.h"
#include "string.h"
#include "functional"

//dfs(i,j) -> from nums[0] to nums[j] and the sum s satisfy s mod 3 = j and max(s)
//trans: dfs(i,j) = max(dfs(i-1,j), dfs(i-1, (j-x)mod3) +x)
// or dfs(i,j) = max(dfs(i-1,j), dfs(i-1, (j+x)mod3) +x)
//boudndary -> dfs(-1,0) = 0 else -inf
int leetcode1262::maxSumDivThree(std::vector<int> &nums) {
    int n = nums.size(), memo[n][3];
    memset(memo, -1, sizeof(memo));

    std::function<int(int, int)> dfs = [&](int i, int j)->int{
        if(i < 0) return j ? INT_MIN : 0;
        int& res = memo[i][j];
        if(res != -1) return res;
        return res = std::max(dfs(i - 1, j), dfs(i - 1, (j + nums[i]) % 3) + nums[i]);
    };
    return dfs(n - 1, 0);
}
