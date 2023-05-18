//
// Created by 25467 on 2023/5/18.
//

#include "leetcode1073.h"
#include "algorithm"
vector<int> leetcode1073::addNegabinary(vector<int> &arr1, vector<int> &arr2) {
    //从低位开始相加，因此需要倒序遍历
    int carry = 0;
    vector<int> res;
    int i = arr1.size()-1;
    int j = arr2.size()-1;
    while(i>=0 || j>=0 || carry!=0){
        if(i>=0){
            carry += arr1[i];
            i--;
        }
        if(j>=0){
            carry += arr2[j];
            j--;
        }

        res.push_back(carry&1);
        carry = - (carry>>1);
    }

    while(res.size()>1 && res[res.size()-1]==0){
        res.pop_back();
    }
    std::reverse(res.begin(), res.end());
    return res;

}
