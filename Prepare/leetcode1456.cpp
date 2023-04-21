//
// Created by 25467 on 2023/4/21.
//

#include "leetcode1456.h"

int leetcode1456::maxVowels(string s, int k) {
    int left=0;
    int right=0;
    int max=0;
    int cnt=0;
    while(right<s.size()){
        char temp=s[right];
        if(temp=='a' || temp=='e' ||temp=='i'||temp=='o'||temp=='u'){
            cnt++;
        }
        right++;
        if(right-left==k){
            max=std::max(max,cnt);
            char c=s[left];
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                cnt--;
            }
            left++;
        }
    }
    return max;
}
