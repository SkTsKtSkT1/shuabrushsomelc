//
// Created by lzw on 2022/12/6.
//

#include "leetcode1805.h"
#include "unordered_set"
int leetcode1805::numDifferentIntegers(string word) {
    std::unordered_set<string> unorderedSet;
    for(int i=0;i<word.size();){
        if(word[i]<'0'||word[i]>'9'){
            i++;
        }else{
            string temp;
            if(word[i]=='0'){
                //去掉前导0
                while(word[i]=='0'){
                    i++;
                }
                while(word[i]>='0' && word[i]<='9'){
                    temp+=word[i];
                    i++;
                }
                unorderedSet.insert(temp);
            }else{
                while(word[i]>='0' && word[i]<='9'){
                    temp+=word[i];
                    i++;
                }
                unorderedSet.insert(temp);
            }
        }
    }
    return unorderedSet.size();
}
