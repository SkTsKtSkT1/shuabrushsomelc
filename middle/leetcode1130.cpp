//
// Created by 25467 on 2023/5/31.
//

#include "leetcode1130.h"
#include "iostream"
using std::vector;
//这道题关键点是要理解中序遍历的意思：左子树就是该数组某个元素K的所有左边元素，右子树就是其所有右边元素，他们两边挑选出最大值的乘积就是题目中要求的一个非叶子节点，也就是左右子树的一个根。
// 然后再根据动态规划，再去求(0到K)和(K+1到n-1)的子问题的最小值。
// 即：dp[i][j]=min(dp[i][j], dp[i][k] + dp[k+1][j] + max[i][k]*max[k+1][j]) 跟leetcode1039算一个套路。 问题抽象过程对我还是好难
int leetcode1130::mctFromLeafValues(std::vector<int> &arr) {
    //1. 状态:左右子树叶节点的个数;选择:节点划分（哪些属于左子树/哪些属于右子树）
    //2. dp[i][j]=x; i数组下标起始点，j表示数组下标终点
    int len = arr.size();
    vector<vector<int>> dp(len, vector<int>(len, 0 ));
    vector<vector<int>> maxVal(len, vector<int>(len, 0 ));

    for(int i=0; i < len; i++){
        maxVal[i][i] = arr[i];
    }
    for(int i = 0; i < len; i++){
        for(int j = i + 1; j < len; j++){
            maxVal[i][j] = std::max(maxVal[i][j-1], arr[j]);
            dp[i][j] = INT_MAX;
        }
    }

    for(int l = 1; l < len; l++){//l=j-i （长度）
        for(int i = 0; i < len - l; i++){
            for(int k = i; k < i+l; k++){
                dp[i][i+l] = std::min(dp[i][i+l],dp[i][k] + dp[k+1][i+l] + maxVal[i][k] * maxVal[k+1][i+l]);
            }
        }
    }
    return dp[0][len-1];
}
