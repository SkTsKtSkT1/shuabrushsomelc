//
// Created by 25467 on 2023/5/5.
//

#include "leetcode2432.h"

int leetcode2432::hardestWorker(int n, vector<vector<int>> &logs) {
    int max_iterval=logs[0][1];
    int min_id=logs[0][0];
    for(int i=logs.size()-1;i>0;i--){
        logs[i][1]-=logs[i-1][1];
    } // delta
    for(int i=0;i<logs.size();i++){
        if(logs[i][1]>max_iterval){
            min_id=logs[i][0];
            max_iterval=logs[i][1];
        }else if(logs[i][1]==max_iterval){
            min_id = std::min(logs[i][0],min_id);
        }
    }
    return min_id;
}
