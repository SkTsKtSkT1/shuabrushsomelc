//
// Created by skt on 2022/10/6.
//

#include "leetcode927.h"

//用加法溢出，那么尝试下标。
vector<int> leetcode927::threeEqualParts(vector<int> &arr) {
    //1.arr中1的个数应该为3的倍数
    int count=0;
    for(int a:arr){
        if(a==1){
            count++;
        }
    }
    if(count%3!=0){
        return {-1,-1};
    }
    int per=count/3;
    //从后往前数，把第三份的值求出来，因为前导0对大小没有影响
    int sum=0;
    int jIndex=0;
    int iIndex=0;
    int p=1;
    for(int i=arr.size()-1;i>=0;i--){
        sum+=p*arr[i];
        p*=2;
        if(arr[i]==1){
            per--;
        }
        if(per==0){
            jIndex=i;//最大的j
            break;
        }
    }
    //然后从头往后数得到一个相等的
    int firstSum=0;
    for(int i=0;i<jIndex;i++){
        firstSum=(firstSum<<1)+arr[i];
        if(firstSum==sum){
            iIndex=i;
            break;
        }else if(firstSum!=sum && i==jIndex-1){
            return {-1,-1};
        }
    }
    int secondSum=0;
    for(int i=iIndex+1;i<jIndex;i++){
        secondSum=(secondSum<<1)+arr[i];
        if(secondSum==sum){
            jIndex=i+1;
            break;
        }else if(secondSum!=sum && i==jIndex-1){
            return {-1,-1};
        }
    }

    return {iIndex,jIndex};


}

vector<int> leetcode927::threeEqualParts1(vector<int> &arr) {
    vector<int> oneIndex;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            oneIndex.push_back(i);
        }
    }
    if(oneIndex.size()%3!=0){
        return {-1,-1};
    }
    if(oneIndex.empty()){
        return {0,int(arr.size())-1};
    }
    int per=oneIndex.size()/3;
    //求出最后一段0的长度
    int backZero=arr.size()-oneIndex.back()-1;
    //大于组间的长度，因为组间长可以用来作为后一组的前导
    if(backZero>oneIndex[per]-oneIndex[per-1]-1|| backZero>oneIndex[2*per]-oneIndex[2*per-1]-1){
        return {-1,-1};
    }
    //比较相对位置，即可
    vector<int> first(oneIndex.begin(),oneIndex.begin()+per);//length is per-1
    vector<int> second(oneIndex.begin()+per,oneIndex.begin()+2*per);
    vector<int> third(oneIndex.begin()+2*per,oneIndex.end());
    for(int i=per-1;i>0;i--){
        if(first[i]-first[i-1]!=second[i]-second[i-1] || second[i]-second[i-1]!=third[i]-third[i-1]){
            return {-1,-1};
        }
    }
    int i=oneIndex[per-1]+backZero; //(0,i]
    int j=oneIndex[2*per-1]+backZero+1;   //(i,j);
    return {i,j};


}