//
// Created by lzw on 2022/11/22.
//

#include "leetcode878.h"
#include "iostream"

//若不看数据范围，只看题面，容易想到的做法是「多路归并」：起始使用两个指针指向 [a, 2a, 3a, ... ] 和 [b, 2b, 3b, ...] 的开头，不断比较两指针所指向的数值大小，从而决定将谁后移，并不断更新顺位计数。
//
//该做法常见，但其复杂度为 O(n)O(n)，对于本题 n = 1e9n=1e9 来说并不可行。
//
//确定线性复杂度的做法不可行后，我们考虑是否存在对数复杂度的做法。
//
//作者：AC_OIer
//链接：https://leetcode.cn/problems/nth-magical-number/solution/by-ac_oier-ln3b/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//int leetcode878::nthMagicalNumber(int n, int a, int b) {
//    int _mod=(int)1e9+7;
//    long result;
//    if(!((a%_mod)%(b%_mod))) {result=(n%_mod)*(b%_mod)%_mod; return (int)result;}
//    if(!((b%_mod)%(a%_mod))) {result=(n%_mod)*(a%_mod)%_mod; return (int)result;}
//
//
//    int pa=0,pb=0;
//
//    while(n>0){
//        if(a%_mod*(pa+1)>b%_mod*(pb+1)){
//            ++pb;
//        }else if(a%_mod*(pa+1)==b%_mod*(pb+1)){
//            ++pa;
//            ++pb;
//        }else{
//            ++pa;
//        }
//        --n;
//    }
//
//    return std::max(pa*a%_mod,pb*b%_mod);
//}

int leetcode878::nthMagicalNumber(int n, int a, int b) {
    //二分查找  能被 a 或 b 整除的数的个数 = 能够被 a 整除的数的个数 + 能够被 b 整除的数的个数 - 既能被 a 又能被 b 整除的数的个数。
    long l=0,r=(long)1e18;
    while(l<r){
        long mid=l+((r-l)>>1);
        if(check(mid,a,b)>=n) r=mid;  //找到第一个大于等于n的 mid满足 所以包含
        else l=mid+1;
    }
    return (int)(r%(1000000007));
}

long leetcode878::check(long x, int a, int b) {
    int c=lcm(a,b);
    return x/a+x/b-x/c;
}

//最大公约数
int leetcode878::gcb(int a, int b) {
 return b==0?a:gcb(b,a%b);
}

//最小公倍数
int leetcode878::lcm(int a, int b) {
    return a*b/gcb(a,b);
}
