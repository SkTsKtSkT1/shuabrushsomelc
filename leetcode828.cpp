//
// Created by lzw on 2022/9/6.
//

#include "leetcode828.h"

int leetcode828::uniqueLetterString(std::string s) {
    //找到字符的所有出现位置，可以得到前缀r-k个，后缀p-r个，因此得到的字符串可以有(r-k)(p-r)个，对每个字符进行统计，即可得到结果。
    int len=s.size();
    int ans=0;
    //记录每个字符出现的位置
    std::vector<int> location[26];
    //head
    for(int i=0;i<26;i++){
        location[i].push_back(-1);
    }
    //遍历字符串
    for(int i=0;i<len;i++){
        location[(s[i]-'A')].push_back(i);
    }
    //tail
    for(int i=0;i<26;i++){
        location[i].push_back(len);
    }
    //计算字符串中每个字符的贡献值
    for(int i=0;i<26;i++){
        if(location[i].size()==2) continue;
        for(int j=1;j+1<location[i].size();j++){
            ans+=(location[i][j]-location[i][j-1])*(location[i][j+1]-location[i][j]);
        }
    }
    return ans;

}

//
//int leetcode828::uniqueLetterString(std::string s) {
//    int len=s.size();
//    int ans=0;
//    std::map<char,std::vector<int>> pos;
//    for(char i='A';i<'Z'+1;i++){
//       pos[i].push_back(-1);
//    }
//    for(char i=0;i<len;i++){
//        pos[s[i]].push_back(i);
//    }
//    for(char i='A';i<'Z'+1;i++){
//        pos[i].push_back(len);
//    }
//
//    for(int i='A';i<'Z'+1;i++){
//        if(pos[i].size()==2) continue;
//        for(int j=1;j+1<pos[i].size();j++){
//            ans+=(pos[i][j]-pos[i][j-1])*(pos[i][j+1]-pos[i][j]);
//        }
//    }
//    return  ans;
//}