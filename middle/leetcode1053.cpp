//
// Created by skt on 2023/4/3.
//

#include "leetcode1053.h"
#include "iostream"
//处理方式为：

//第一步：从当前序列的后往前找，找到第一个降序的位置（A[i]>A[i+1]），则必存在能构造比当前小的序列。

//第二步：把A[i]后面的数字中，小于A[i]且最接近A[i]的值的数字找出来，和A[i]交换。

vector<int> leetcode1053::prevPermOpt1(vector<int> &arr) {
    int n=arr.size();
    int index=-1;
    for(int i=n-1;i>0;--i){
        if(arr[i]<arr[i-1]){
            index=i-1;
            break;
        }
    }
    if(index==-1) return arr;

    int second_index=n;
    int delta=INT_MAX;
    for(int i=n-1;i>index;--i){
        if(arr[i]<arr[index] && arr[index]-arr[i]<=delta && i<second_index){ //相同要最左边的！
            second_index=i;
            delta=arr[index]-arr[second_index];
        }
    }

    std::swap(arr[second_index],arr[index]);
    return arr;
}

std::ostream &leetcode1053::operator<<(const vector<int> &arr) {
    for(vector<int>::const_iterator it= arr.begin(); it != arr.end(); it++){
        std::cout<<(*it)<<" ";
    }
    std::cout<<std::endl;
    return std::cout;
}