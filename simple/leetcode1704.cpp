//
// Created by lzw on 2022/11/11.
//

#include "leetcode1704.h"
#include "set"

bool leetcode1704::halvesAreAlike(string s) {
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
        char c=s[i];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            cnt++;
        }
        c=s[i+s.size()/2];
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U'){
            cnt++;
        }
    }
    return cnt==0;
}
