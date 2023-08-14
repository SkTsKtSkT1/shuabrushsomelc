//
// Created by skt on 2023/8/15.
//

#include "leetcode833.h"
#include "map"
std::string leetcode833::findReplaceString(std::string s, std::vector<int> &indices, std::vector<std::string> &sources,
                                           std::vector<std::string> &targets) {
    //只能应对0~9个操作
//    std::string mark = s;
//    for(int i = 0; i < indices.size(); ++i){
//        bool need_mark = true;
//        int indice = indices[i];
//        for(int j = 0; j < sources[i].size(); ++j){
//            if(s[indice + j] != sources[i][j]){
//                need_mark = false;
//                break;
//            }
//        }
//        if(need_mark){
//            for(int j = 0; j < sources[i].size(); ++j){
//                mark[indice + j] = '0' + i;
//            }
//        }
//    }
//    std::string res;
//    for(int i = 0; i < mark.size();){
//        if(isdigit(mark[i])){
//            int index = mark[i] - '0';
//            while(mark[i] == index + '0'){
//                ++i;
//            }
//            res += targets[index];
//        }else{
//            res += mark[i];
//            ++i;
//        }
//    }
//    return res;
//}
    std::map<int, std::string> mp;
    for(int i = 0; i < indices.size(); ++i){
        if(s.substr(indices[i], sources[i].size()) == sources[i]){
            mp[indices[i]] = targets[i];
            for(int j = 1; j < sources[i].size(); ++j){
                s[indices[i] + j] = '*';
            }
            //s[indices[i]] = 's'; //可能字符串原本包含s
            s[indices[i]] = '|';
        }
    }
    std::string res;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] == '*'){
            continue;
        }else if(s[i] == '|'){
            res += mp[i];
        }else{
            res += s[i];
        }
    }
    return res;
}
