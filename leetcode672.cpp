//
// Created by lzw on 2022/9/15.
//

#include "leetcode672.h"

//开关1: 1,2,3,4,5,6,...
//开关2: 2,4,6,8,...
//开关3: 1,3,5,7,...
//开关4: 1,4,7,10...  3k+1
//取T=6. 1 2 3 4 5 6 与 7 8 9 10 11 12状态一样
//如果按压偶数次 则状态为0
//假设按压1a 2b 3c 4d
//1 (a+c+d)%2
//2 (a+b)%2
//3 (a+c)%2
//4 (a+b+d)%2
//5 (a+c)%2
//6 (a+b)%2
//可以看出 26 35状态一样，讨论4的状态，若1与3相同，则4与2相同，若1与3不同，则4与2不同
//ref:https://leetcode.cn/problems/bulb-switcher-ii/solution/dengp-by-capital-worker-51rb/
// 1010  1111 1001 1100 0101 0000 0110 0011 最多八种状态 枚举按1 2 3 4 5。。。的结果
int leetcode672::flipLights(int n, int presses) {
    if(presses==0) return 1;
    if(n==1) return 2;
    else if(n==2){
        return presses==1?3:4;
    }else{//按一次是4，两次是7，三次以上就是8   n>=3
        return presses==1? 4: (presses==2?7:8);
    }
}