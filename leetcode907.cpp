//
// Created by lzw on 2022/10/28.
//

#include "leetcode907.h"

int leetcode907::sumSubarrayMins(vector<int> &arr) {
    //对于每个index，找到最近的比其小的数的下标，超出为-1 和arr.size();
    int len =arr.size();
    int ans=0;
    //单调栈两次//yici 针对每个出栈的元素，当前元素A[i]不就是向右比它更小的第一个元素

    //实际上，当我们从栈中弹出某个arr[cur] 时，其右边界必然是导致其弹出的 arr[r]（当前所遍历到的元素）
    // 而 arr[cur]若存在左边界，必然是位于 cur 栈中的前一位置
    // 即 arr[cur] 弹出后的新栈顶元素（若不存在物理左边界，则左边界为 -1）。

    //vector<int> left(len,-1),right(len,len);
    std::stack<int> stk;
    for(int i=0;i<=len;i++){
        int temp=i<len?arr[i]:0;//如果一个数是最小的，那么有边界应当是len
        while(!stk.empty() && arr[stk.top()]>=temp){
            int cur=stk.top();
            stk.pop();
            int l=stk.empty()?-1:stk.top(); //如果当前元素出栈 左边界就是出栈后的栈顶元素
            int r=i;
            ans+=(cur-l)*1L*(r-cur)%_mod*arr[cur]%_mod;
            ans%=_mod;
        }
        stk.push(i);
    }
    return ans;
}