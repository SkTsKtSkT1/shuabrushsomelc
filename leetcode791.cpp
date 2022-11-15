//
// Created by skt on 2022/11/13.
//

#include "leetcode791.h"
#include "unordered_map"
#include "algorithm"
//string leetcode791::customSortString(std::string order, std::string s) {
//    //使用char,int存储order信息，然后遍历s，找到没有的统统加在后面
//    std::unordered_map<char,int> m;
//    for(int i=0;i<order.size();i++){
//        m[order[i]]=i;
//    }
//    string charInOrder,charIns;
//    for(char & c : s){
//        if(m.count(c)){
//            charInOrder+=c;
//        }else{
//            charIns+=c;
//        }
//    }
//    std::sort(charInOrder.begin(),charInOrder.end(),[&](char a,char b)->bool {
//        return m[a]<m[b];
//    });
//    return charInOrder+charIns;
//
//
//}

string leetcode791::customSortString(std::string order, std::string s) {
    //使用char,int存储order信息，然后遍历s，不存在的就设置在order里很大，从而进行一次排序
    //其实可以用vector<int> 将0-25作为索引 存储为权重 没有的设置为0
    std::unordered_map<char,int> m;
    for(int i=0;i<order.size();i++){
        m[order[i]]=i;
    }

    for(char & c : s){
        if(!m.count(c)){
            m[c]=27;
        }
    }
    sort(s.begin(),s.end(),[&](char a,char b)->bool {
        return m[a]<m[b];
    });
    return s;


}