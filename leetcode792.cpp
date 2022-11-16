//
// Created by skt on 2022/11/17.
//

#include "leetcode792.h"
#include "queue"
int leetcode792::numMatchingSubseq(std::string s, vector<std::string> &words) {
    //中间也可以删除 所以只要能单词每个字母都全部匹配就好
    vector<std::queue<std::pair<int,int>>> bucket(26);
    //buckets中保存的是pair<int, int>, 分别是单词在wrods中的索引， 和该单词下一个要处理的字母在该单词中的索引。
    for(int i=0;i<words.size();i++){
        bucket[words[i][0]-'a'].emplace(i,0);
    }
    int res=0;
    for(const char& c:s){
        //每次把每一个桶都处理一下，然后加入新的
        std::queue<std::pair<int,int>> &q=bucket[c-'a'];
        for(int i=q.size();i>0;i--){ //有重复的，所以不能用while和正序的for,第一次就确定循环次数
            auto [wordIndex, posIndex]=q.front();
            q.pop();
            posIndex++;
            if(posIndex==words[wordIndex].size()){
                res++;
            }else{
                bucket[words[wordIndex][posIndex]-'a'].emplace(wordIndex, posIndex);
            }
        }
    }
    return res;

}