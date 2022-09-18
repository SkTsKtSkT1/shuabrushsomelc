//
// Created by skt on 2022/9/17.
//

#include "leetcode1642.h"

int leetcode1642::maxLengthBetweenEqualCharacters(std::string s) {
    int len=s.size();
    if(len==1) return -1;
    //初始化记录下标位置数组，然后遍历 剔除掉出现低于2次的，然后分别计算得到最大值
    //麻了，最大的中间可以包含自己，所以只需要找到第一次出现然后不断迭代。。。
    vector<int> firstIndex(26,-1);
    int ans=-1;
    for(int i=0;i<len;i++) {
        if(firstIndex[s[i]-'a']<0){
            firstIndex[s[i]-'a']=i;
        }else{
            ans=std::max(ans,i-firstIndex[s[i]-'a']-1);
        }
    }
    return  ans;
//    vector<int> pos[26];
//    for(int i=0;i<len;i++){
//        pos[s[i]-'a'].push_back(i+1);//initial is 0 ,so index+1;
//    }
//    int max=-1;
//    for(const vector<int>& p:pos){
//        if(p.size()<2) continue;
//        for(int j=1;j<p.size();j++){
//            int temp=p[j]-p[j-1]-1;
//            if(temp>max) max=temp;
//        }
//    }
//    return max;


}
