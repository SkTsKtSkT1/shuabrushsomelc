//
// Created by skt on 2023/8/21.
//

#include "leetcode2337.h"
#include <iostream>
bool leetcode2337::canChange(std::string start, std::string target) {
    //1.去掉下划线需要相同
    //2.L不可以右移，R不可以左移，所以如果L往右了或R往左了，就false
    std::string startZip;
    std::string targetZip;
    for(int i = 0; i < start.size(); ++i){
        if(start[i] != '_'){
            startZip += start[i];
        }
        if(target[i] != '_'){
            targetZip += target[i];
        }
    }
    if(targetZip != startZip){
        return false;
    }
    for(int i = 0, j = 0; i < start.size() && j < target.size(); ++i, ++j){
        while(start[i] == '_'){
            ++i;
        }
        while(target[j] == '_'){
            ++j;
        }
        if(start[i] == 'L'){
            if(i < j) {
                return false;
            }
        }else if(i > j) {
            return false;
        }
    }
    return true;
}
