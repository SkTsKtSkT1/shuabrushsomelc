//
// Created by skt on 2023/4/29.
//

#include "leetcode2423.h"

bool leetcode2423::equalFrequency(string word) {
    int freq[26]={0};
    for(char& w:word){
        freq[w-'a']++;
    }

    int cur_frep;
    for(int i=0;i<26;i++){
        freq[i]--;
        if(freq[i]!=-1 && check(freq)) return true;
        freq[i]++;
    }
    return false;
}

bool leetcode2423::check(int *a) {
    int cur=-1;
    for(int i=0;i<26;i++){
        if(cur==-1 && a[i]!=0) cur=a[i];
        if(a[i]!=0 && a[i]!=cur) return false;
    }
    return true;
}
