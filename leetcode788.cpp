//
// Created by lzw on 2022/9/25.
//

#include "leetcode788.h"


int leetcode788::rotatedDigits(int n) {
    int ans=0;
    for(int i=1;i<=n;i++){
        if(maybeGood(i)) ans++;
    }
    return ans;
}

bool leetcode788::maybeGood(int n){
    //只有由数字0,1,2,5,6,8,9组成的数字才有可能是好数。
    //循环处理每一位，且必须有一位是2，5，6，9
    int x=0,p=1,y=n;
    while(n!=0){
        int rot=rotate[n%10];
        if(rot==-1) return false;
        x+=rot*p;
        n/=10;
        p*=10;
    }
    return x!=y;
}
