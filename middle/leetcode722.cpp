//
// Created by 25467 on 2023/8/3.
//

#include "leetcode722.h"

std::vector<std::string> leetcode722::removeComments(std::vector<std::string> &source) {
    std::string cur;
    int status = 0; //0: str, 1:pre, 2.block, 3.block_end_pre
    std::vector<std::string> res;
    for(const std::string& s : source){
        for(const char& c : s){
            if(status == 0){
                if(c == '/'){
                    status = 1;
                }else{
                    cur += c;
                }
            }else if(status == 1){
                if(c == '/'){
                    status = 0;
                    break; //end
                }else if(c == '*'){
                    status = 2;
                }else{
                    status = 0;
                    cur += '/';
                    cur += c;
                }
            }else if(status == 2){
                if(c == '*'){
                    status = 3;
                }
            }else if(status == 3){
                if(c == '/'){
                    status = 0;
                }else if(c != '*'){
                    status = 2;
                }
            }
        }
        if(status == 1){ //如果到了结尾还是pre状态，说明不是注释 加上改变状态使用的 /
            cur += '/';
            status = 0;
        }else if(status ==3) status = 2;
        if(cur.size() != 0 && status == 0){
            res.push_back(cur);
            cur = "";
        }
    }
    return res;
}
