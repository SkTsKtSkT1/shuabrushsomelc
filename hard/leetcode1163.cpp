//
// Created by 25467 on 2023/4/24.
//

#include "leetcode1163.h"
//排在最后的那个子串一定是s的某个后缀。因为前缀相同的子串，长度越长的字典序越靠后。对于s的某个字典序靠后的子串，一定可以通过将其延伸到s的末端使得其字典序位置更靠后，如下图所示。
//https://leetcode.cn/problems/last-substring-in-lexicographical-order/solution/python3javacgotypescript-yi-ti-yi-jie-sh-3amj/
string leetcode1163::lastSubstring(string s) {
    int n=s.size();
    int i=0,j=1,k=0;
    //i指向的是当前找到字典序最大的字符，j指向的是当前要进行比较的字符。使用一个位移指针k，来比较i和j构成的子串[i,..,i + k]和[j,...,j + k]的顺序。
    char ch1,ch2;
    while(j+k<n){
        ch1=s.at(i+k);
        ch2=s.at(j+k);
        if(ch1==ch2){
            k++;
        }else if(ch1<ch2){
            i+=k+1;
            k=0;
            if(i>=j){
                j=i+1;
            }
        }else{
            j+=k+1;
            k=0;
        }
    }
    return s.substr(i);
}
