//
// Created by skt on 2023/9/2.
//

#include "leetcode2511.h"

int leetcode2511::captureForts(std::vector<int> &forts) {
//    int n = forts.size();
//    int pre = -1;
//    int ans = 0;
//    for(int i = 0; i < n; ++i){
//        if(forts[i] != 0){
//            if(pre == -1){
//                pre = i;
//            }else if(forts[i] != forts[pre]){
//                ans = std::max(ans, i - pre - 1);
//                pre = i;
//            }
//        }
//    }
//    return ans;
    int n = forts.size();
    int pre = -1;
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(forts[i] != 0){
            if(pre != -1 && forts[i] != forts[pre]){
                ans = std::max(ans, i - pre - 1);
            }
            pre = i;
        }
    }
    return ans;
}
