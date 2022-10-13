//
// Created by skt on 2022/10/14.
//

#include "leetcode940.h"

int leetcode940::distinctSubseqII(std::string s) {
    //1、首先假如子序列的倒数第一个字母不同，那么就是不同的子序列，同理，倒数第一个字母相同的时候，如果倒数第二个字母不同，
    // 那就是不同的子序列，以此类推；
    // 2、假如一个字母不是第一次出现，那么一部分以这个字母为末尾的子序列，可以换为由之前上一次出现的这个字母为结尾的子序列，
    // 因此只需要考虑倒数第二个字母上一次出现的位置的即可（第1条说了，倒数第二个字母不同的子序列就是不同的）；
    // 3、这样没遇到一个字母，就可以用之前的26个字母出现的子序列为末尾的次数之和，再加上单独的他自己；
    // 4、总和就是26中2末尾的子序列种数之和（末尾不重复）
    vector<long> line(26,0);
    long ans=0;
    //https://leetcode.cn/problems/distinct-subsequences-ii/solution/by-da-yu-bt-jy18/
    //对于第i个位置的字符j，其以j结尾的字串的个数等于所有以各种字符结尾数字之和+1，即思考前缀
    //可以理解为以j结尾，如果不考虑j的话，前面固定的只有各种字符结尾数字之和个，再加上单个的一个该字符
    // （原本abca 考虑最后一位，对于前面有a=1 b=2 c=4 如果再来一个a就变成了aa 因此还需要+1 则a=1+2+4+1=8 总和为14
    //总共有各个字母结尾的数字之和个
    for(int i=0;i<s.size();i++){
        long sum=0;
        for(long l:line){
            sum=(sum+l)%_mod;
        }
        line[s[i]-'a']=sum+1;
    }
    for(long l:line){
        ans=(ans+l)%_mod;
    }
    return ans;
}