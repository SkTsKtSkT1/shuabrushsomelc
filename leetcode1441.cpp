//
// Created by skt on 2022/10/15.
//

#include "leetcode1441.h"
#include "iostream"
vector<string> leetcode1441::buildArray(vector<int> &target, int n) {
    vector<string> result;
    for(int i=0,j=1;i<target.size();i++){
        //if(target[i]==j){
        //    result.emplace_back("Push");
        //    j++;
        //}else{
            while (target[i] != j) {
                result.emplace_back("Push");
                result.emplace_back("Pop");
                j++;
            }
            result.emplace_back("Push");
            j++;
        //}
    }
    return result;
}

std::ostream &leetcode1441::operator<<(vector<string> s) {
    for(vector<string>::iterator _=s.begin();_!=s.end();_++){
        std::cout<<*(_)<<std::endl;
    }
    return std::cout;
}
