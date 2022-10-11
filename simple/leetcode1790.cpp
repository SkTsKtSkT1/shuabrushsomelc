//
// Created by skt on 2022/10/11.
//

#include "leetcode1790.h"

bool leetcode1790::areAlmostEqual(std::string s1, std::string s2) {
//If you can make s1=s2 by only swap once,then s1 and s2 must only have 2 differents
//If index i s1[i]=s2[i] means the same while s1[i]!=s2[i] means different
//if index j satisfy s2[j]=s1[i] then times++ if times>1 return false else true
    int len=s1.size();
    //record the different index and value
    std::vector<int> diff;
    //to get how many different between s1 and s2
    for(int i=0;i<len;i++){
        if(s1[i]==s2[i]){
            continue;
        }else{
            diff.push_back(i);
        }
    }
    if(diff.empty()){
        return true;
    }
    else if(diff.size()!=2) {
        return false;
    }

    int i1=diff[0],i2=diff[1];
    if(s1[i1]==s2[i2] && s1[i2]==s2[i1]){
        return true;
    }
    return false;



}
