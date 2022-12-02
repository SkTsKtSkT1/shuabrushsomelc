//
// Created by lzw on 2022/12/2.
//

#include "letcode1769.h"
#include "cmath"
//vector<int> letcode1769::minOperations(string boxes) {
//    int len=boxes.size();
//    vector<int> place;
//    vector<int> ans(len);
//
//    //1.get the 1's place
//    for(int i=0;i<len;i++){
//        if(boxes[i]=='1'){
//            place.push_back(i);
//        }
//    }
//
//    //2.cal answer
//    for(int i=0;i<len;i++){
//        int temp=0;
//        for(int j=0;i<place.size();j++){
//            temp+=abs(place[j]-i);
//        }
//        ans[i]=temp;
//    }
//
//    return ans;
//}

vector<int> letcode1769::minOperations(string boxes) {
    //每当发现字符‘1’，则计算每个盒子的操作数
    vector<int> res(boxes.size());
    for(int i=0;i<boxes.size();i++){
        for(int j=0;j<res.size();j++){
            res[j]+=abs(j-i);
        }
    }
    return res;
}